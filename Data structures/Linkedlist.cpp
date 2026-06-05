#include <iostream>
using namespace std;

template <typename T>


class Node {
public:
    T data;
    Node* next;
    Node(T val) {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class linkedlistiterator {
private:
    Node<T>* current;
public:  

    linkedlistiterator() {                                //O(1)
        current = nullptr;
    }
    linkedlistiterator(Node<T>* node) {                   //O(1)
        current = node;
    }

    T& operator*() {                                    //O(1)
        return current->data;
    }

    linkedlistiterator& operator++() {                 //O(1)
        if (current != nullptr) {
            current = current->next;
        }
        return *this;
    }

    bool operator==(const linkedlistiterator& other) const {    //O(1)
        return current == other.current;
    }

    bool operator!=(const linkedlistiterator& other) const {    //O(1)
        return current != other.current;
    }

};


template <typename T>
class LinkedList {
protected:
    Node<T>* head;
    Node<T>* tail;
    int size;
private:
    void copylist(const LinkedList& other){                 //O(n)
        Node<T>* current , *newNode;
        if(head != nullptr) destroyList();
        if(other.head == nullptr) {
            head = tail = nullptr;
            size = 0;
        }
        else {
            current = other.head;
            size = other.size;
            head = new Node<T>(current->data);
            head->next = nullptr;
            tail = head;
            current = current->next;
            while(current != nullptr) {
                newNode = new Node<T>(current->data);
                newNode->next = nullptr;
                tail->next = newNode;
                tail = newNode;
                current = current->next;
            }
        }
    }
    

public:
    LinkedList() {                                          //O(1)
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void destroyList() {                                    //O(n)
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        size = 0;
    }

    ~LinkedList() {             //O(n)
        destroyList();
    }

    void initializeList() {          //O(n)
        destroyList();
    }

    LinkedList& operator=(const LinkedList& other) {            //O(n)
        if (this != &other) copylist(other); 
        return *this;
    }

    LinkedList(const LinkedList& other) {          //O(n)       
        copylist(other);
    }


    bool isEmpty() const {                  //O(1)
        return head == nullptr;
    }


    linkedlistiterator<T> begin() const {       //O(1)  
        return linkedlistiterator<T>(head);
    }
    linkedlistiterator<T> end() const {         //O(1)
        return linkedlistiterator<T>(nullptr);
    }

    int getsize() const {             //O(1)    
        return size;
    }

    T front() const {                   //O(1)
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    T back() const {                //O(1)
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return tail->data;
    }

    //O(n)
    void clear() {
        destroyList();
    }

    //O(n)
    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    virtual bool search(const T& val) const = 0;
    virtual void insertfirst(const T& val) = 0;
    virtual void insertlast(const T& val) = 0;
    virtual void deletenode(const T& val) = 0;

};

template <typename T>

class unorderedlinkedlist : public LinkedList<T> {
public:
    bool search(const T& val) const {      //O(n)
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertfirst(const T& val) {
        Node<T>* newNode = new Node<T>(val);

        if (this->search(val)) throw runtime_error("Value already exists in the list.");  
        if (newNode == nullptr) throw runtime_error("Memory allocation failed.");

        if (isEmpty()) this->head = this->tail = newNode;
        
        else {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void insertlast(const T& val) {
        Node<T>* newNode = new Node<T>(val);

        if (this->search(val)) throw runtime_error("Value already exists in the list.");  
        if (newNode == nullptr) throw runtime_error("Memory allocation failed.");

        if (isEmpty()) this->head = this->tail = newNode;
        
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void deletenode(const T& val) override{
        if (this->isEmpty()) {
            throw runtime_error("List is empty");
        }
  
        Node<T>* current = this->head;
        Node<T>* previous = nullptr;
        bool found = false;

        while (current != nullptr){
            if(current->data == val){
                found = true;
                break;
            }
            previous = current;
            current = current->next;
        }
        if (current == nullptr) throw runtime_error("Value not found in the list");
        

        // First case : Deleting the head node
        if(current == this->head){
            this->head = this->head->next;
            if(this->head == nullptr) this->tail = nullptr;
        }
        // Second case : Deleting the tail node
        else if(current == this->tail){
            this->tail = previous;
            this->tail->next = nullptr;

        }
        // Third case : Deleting a node in the middle
        else {
            previous->next = current->next;
        }
        delete current;
        this->size--;
    }

};


class orderedLinkedList : public LinkedList<int> {
public:

    //O(n)
    bool search(const int& val) const { 
        if (this->isEmpty()) return false;
        Node<int>* current = this->head;
        bool found = false;
        while (current != nullptr) {
            if (current->data >= val) {
                found = true;
                break;
            }
            current = current->next;
        }
        if(found) found = (current->data == val);
        return found;
    }

    //O(n)
    void insert(const int& val){
        Node<int>* newNode = new Node<int>(val);
        if (newNode == nullptr) throw runtime_error("Memory allocation failed.");

        if (this->isEmpty()) this->head = this->tail = newNode;           // First case : Inserting into an empty list

        else {
            Node<int>* current = this->head;
            Node<int>* previous = nullptr;
            bool found = false;

            while (current != nullptr && !found) {
                if (current->data >= val) {
                    found = true;
                }
                else {
                    previous = current;
                    current = current->next;
                }
            }

            if(current == this->head){                         // Second case : Inserting before the head node
                newNode->next = this->head;
                this->head = newNode;
            }

            else if(current == nullptr){                      // Third case : Inserting after the tail node
                previous->next = newNode;
                this->tail = newNode;
            }

            else {                                          // Fourth case : Inserting in the middle
                previous->next = newNode;
                newNode->next = current;
            }
      
        }

        this->size++;
    }



    //O(n)
    void deletenode(const int& val) override{
        if (this->isEmpty()) {
            throw runtime_error("List is empty");
        }
  
        Node<int>* current = this->head;
        Node<int>* previous = nullptr;
        bool found = false;

        while (current != nullptr){
            if(current->data >= val){
                found = true;
                break;
            }
            previous = current;
            current = current->next;
        }
        if (current == nullptr || current->data != val) throw runtime_error("Value not found in the list");
        

        // First case : Deleting the head node
        if(current == this->head){
            this->head = this->head->next;
            if(this->head == nullptr) this->tail = nullptr;
        }
        // Second case : Deleting the tail node
        else if(current == this->tail){
            this->tail = previous;
            this->tail->next = nullptr;

        }
        // Third case : Deleting a node in the middle
        else {
            previous->next = current->next;
        }
        delete current;
        this->size--;
    }
};







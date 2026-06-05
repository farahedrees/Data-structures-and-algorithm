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

    linkedlistiterator() {
        current = nullptr;
    }
    linkedlistiterator(Node<T>* node) {
        current = node;
    }

    T& operator*() {
        return current->data;
    }

    linkedlistiterator& operator++() {
        if (current != nullptr) {
            current = current->next;
        }
        return *this;
    }

    bool operator==(const linkedlistiterator& other) const {
        return current == other.current;
    }

    bool operator!=(const linkedlistiterator& other) const {
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
    void copylist(const LinkedList& other){
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
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void destroyList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        destroyList();
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) copylist(other); 
        return *this;
    }

    LinkedList(const LinkedList& other) {
        copylist(other);
    }


    bool isEmpty() const {
        return head == nullptr;
    }

    bool search(const T val) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    linkedlistiterator<T> begin() const {
        return linkedlistiterator<T>(head);
    }
    linkedlistiterator<T> end() const {
        return linkedlistiterator<T>(nullptr);
    }

    int getsize() const {
        return size;
    }

    T front() const {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    T back() const {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return tail->data;
    }

    void clear() {
        destroyList();
    }
    
    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    virtual void insert(const T val) = 0;

    virtual void deletenode(const T val) = 0;


};


template <typename T>

class unorderedlinkedlist : public LinkedList<T> {
public:

    void insertfirst(const T val) {
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

    void insertlast(const T val) {
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

    void deletenode(const T val) override {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
    }
};
template <typename T>
class sortedlinkedlist : public LinkedList<T> {
};


#include <iostream>
using namespace std;

template <typename T>
struct Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoublyLinkedList() {
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
        head = nullptr;
    }
    ~DoublyLinkedList() {
        destroyList();
    }
    void initializeList() {
        destroyList();
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    int getsize() const {
        return size;
    }
    T getfirst() const {
        if (isEmpty()) throw runtime_error("List is empty");
        return head->data;
    }
    T getlast() const {
        if (isEmpty()) throw runtime_error("List is empty");
        return tail->data;
    }

    void printList() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }


    bool search(const T& val) const {
        Node<T>* current = head;
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
        if (newNode == nullptr) throw runtime_error("Memory allocation failed.");

        if (isEmpty()) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void insertlast(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if (newNode == nullptr) throw runtime_error("Memory allocation failed.");

        if (isEmpty()) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void deletefirst() {
        if (isEmpty()) throw runtime_error("List is empty");
        Node<T>* temp = head;
        if (head == tail) head = tail = nullptr;     // Only one node in the list
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void deletelast() {
        if (isEmpty()) throw runtime_error("List is empty");
        Node<T>* temp = tail;
        if (head == tail) head = tail = nullptr;     // Only one node in the list
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void deleteNode(const T& val){
        if(isEmpty()) throw runtime_error("List is empty");
        Node<T>* current = head;
        bool found = false;
        while(current != nullptr){
            if(current->data == val){
                found = true;
                break;
            }
            current = current->next;
        }
        if(found){
            if(current == head) deletefirst();
            else if(current == tail) deletelast();
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
        }
        else throw runtime_error("Value not found in the list");
    }

};
//implementation of Queue using doublylinked list

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;
    Node(T x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>   
class Queue
{
private:
    Node<T>* top;
    Node<T>* rear;
public:
    Queue(){
        top = NULL;
        rear = NULL;
    }

    void destroyqueue() {
        while (top != NULL) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    ~Queue() {
        destroyqueue();
    }
    void enqueue(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = NULL;
        newNode->prev = rear;
        if (rear != NULL) {
            rear->next = newNode;
        } else {
            top = newNode;
        }
        rear = newNode;
    }
    void dequeue() {
        if (top == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        if (top != NULL) {
            top->prev = NULL;
        } else {
            rear = NULL;
        }
        delete temp;
    }
    T peek() {
        if (top == NULL) {
            throw runtime_error("Queue is empty");
        }
        return top->data;
    }
    bool isEmpty() {
        return top == NULL;
    }
    void display() {
        if (top == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node<T>* temp = top;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int size() {
        int count = 0;
        Node<T>* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

};



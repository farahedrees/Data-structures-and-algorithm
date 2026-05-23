//implementation of stack using linked list

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T x) {
        data = x;
        next = NULL;
    }
};

template <typename T>   
class Stack
{
private:
    Node<T>* top;
public:
    Stack(){
        top = NULL;
    }
    void destroyStack() {
        while (top != NULL) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
    ~Stack() {
        destroyStack();
    }
    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow\n";
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    T peek() {
        if (top == NULL) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }
    bool isEmpty() {
        return top == NULL;
    }
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};



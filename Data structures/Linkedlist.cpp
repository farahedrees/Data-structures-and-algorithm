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
        head = nullptr;
    }
    ~LinkedList() {
        destroyList();
    }


};


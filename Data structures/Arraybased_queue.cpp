//implementing queue using array

#include <iostream>
using namespace std;

template <typename T>

class queue{
    private:
    int first , last;
    int size , capacity;
    T *arr;
    public:

    queue(int c){                   //default constructor
        capacity = c;
        arr = new T[capacity];
        size = 0;
        first = 0;
        last = -1;
    }
    T front(){
        if(size == 0) throw runtime_error("Empty queue");
        return arr[first];
    }
    T back(){
        if(size == 0) throw runtime_error("Empty queue");
        return arr[last];
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == capacity;
    }

    //enqueue operation is O(1) 
    void enqueue(const T& element){
        if(isFull()) throw runtime_error("Full queue");
        arr[size] = element;
        last = size;
        size++;
    }

    //dequeue operation is O(n) because we have to shift all the elements to the left after removing the first element
    void dequeue(){
        if(isEmpty()) throw runtime_error("Empty queue");
        for(int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
        last = size - 1;
    
    }

    //circular queue implementation
    void pushelement(const T& element){
        if(isFull()) throw runtime_error("Full queue");
        last = (last + 1) % capacity;
        arr[last] = element;
        size++;
    }

    void deQueue(){
        if(isEmpty()) throw runtime_error("Empty queue");
        first = (first + 1) % capacity;
        size--;
    }
};
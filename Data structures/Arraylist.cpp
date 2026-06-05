#include <iostream>



using namespace std;

template <typename T>

class Arraylist {
private:
    T* arr;
    int capacity;
    int size;
public:
    Arraylist(int c) {                                       // O(1)
        capacity = c;
        arr = new T[capacity];
        size = 0;
    }

    // copy constructor
    Arraylist(const Arraylist& other) {                        // O(n)   
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        if (other.arr == nullptr) {
            arr = nullptr;
            return;
        }
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // copy assignment operator  
    Arraylist& operator=(const Arraylist& other){               // O(n)
        if (this != &other)      {     
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new T[capacity];
            if (other.arr == nullptr) {
                arr = nullptr;
                return *this;
            }
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }


    bool isEmpty() {                               // O(1)
        return size == 0;
    }
    bool isFull() {                                // O(1)
        return size == capacity;
    }
    int getSize() {                                // O(1)
        return size;
    }
    int getCapacity() {                           // O(1)
        return capacity;
    }
    void clear() {                                // O(1)
        size = 0;
    }
 
    ~Arraylist() {                               // O(1)
        delete[] arr;
    }

    // O(n) because we have to shift all the elements to the right after inserting the new element
    void insertat(int index, const T& val) {                
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");    
        if (isFull()) throw std::overflow_error("Arraylist is full");

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        size++;
    }

    // O(1)
    void insertend(const T& val) {                              // O(1)
        if (isFull()) throw std::overflow_error("Arraylist is full");
        arr[size] = val;
        size++;
    }


    // O(n) because we have to shift all the elements to the right after inserting the new element
    void removeat(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // O(1)
    T retrieveat(int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        return arr[index];
    }


    // O(1)
    void retrieve(int index, T& val) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        val = arr[index];
    }

    // O(1)
    void replaceat(int index, const T& val) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        arr[index] = val;
    }


    int find(const T& val) {                              // O(n)
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        for (int i = 0; i < size; i++) {
            if (arr[i] == val) return i;
        }
        return -1; // not found
    }

    void insertbegin(const T& val) {                             // O(n)
        if (isFull()) throw std::overflow_error("Arraylist is full");

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        size++;
    }

    void insert(const T& val) {                              // O(n)
        if (isFull()) throw std::overflow_error("Arraylist is full");

        if(isEmpty()) {
            arr[0] = val;
            size++;
            return;
        }

        else{
            int index = find(val);
            if(index != -1) {
                cout << "Element already exists at index " << index << endl;
                return;
            }
            insertend(val);
        }
    }

    void remove(const T& val) {                              // O(n)
        if (isEmpty()) throw std::underflow_error("Arraylist is empty");

        int index = find(val);
        if (index == -1) throw std::invalid_argument("Element not found");

        removeat(index);
    }



};
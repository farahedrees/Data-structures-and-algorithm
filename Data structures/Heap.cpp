#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class MaxHeap {

private:
    vector<int> data;

public:

    MaxHeap() {}                        // Constructor

    // Heapify down to maintain max heap property
    void maxheapify(int index) {                             // Time complexity: O(log n)
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if(left < data.size() && data[left] > data[largest]) largest = left;
        if(right < data.size() && data[right] > data[largest]) largest = right;
        if(largest != index) {
            swap(data[index], data[largest]);
            maxheapify(largest);
        }
    }

    // Build the max heap from an unsorted array 
    void buildMaxHeap() {                                     //Time complexity: O(n)
         for(int i = data.size() / 2 - 1; i >= 0; i--) {
            maxheapify(i);
        }
    }

    void insert(int value){
        data.push_back(value);
        int current = data.size() - 1;
        while (current > 0 && data[current] > data[(current - 1) / 2]) {
            swap(data[current], data[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    void search(int value) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == value) {
                cout << "Value found at index: " << i << endl;
                return;
            }
        }
        cout << "Value not found in the heap\n";
    }


    void deleteRoot() {
        if (data.size() == 0) {
            cout << "Heap is empty\n";
            return;
        }
        data[0] = data[data.size() - 1];
        data.pop_back();

        if(!data.empty()) {
            maxheapify(0);
        }
    }

    void heapsort(){
        buildMaxHeap();
        for(int i = data.size() - 1; i > 0; i--) {
            swap(data[0], data[i]);
            maxheapify(0);
        }
    }

};

class MinHeap {
private:
    vector<int> data;
public:
    MinHeap() {}                        // Constructor 
 
    // Heapify down to maintain min heap property
    void minheapify(int index) {                             //Time complexity: O(log n)
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if(left < data.size() && data[left] < data[smallest]) smallest = left;
        if(right < data.size() && data[right] < data[smallest]) smallest = right;
        if(smallest != index) {
            swap(data[index], data[smallest]);
            minheapify(smallest);
        }
    }

    // Build the min heap from an unsorted array
    void buildMinHeap() {       
        for(int i = data.size() / 2 - 1; i >= 0; i--) {       // Time complexity: O(n)
                minheapify(i);
        }     
    }

    void insert(int value){                               // Time complexity: O(log n)
        data.push_back(value);
        int current = data.size() - 1;
        while (current > 0 && data[current] < data[(current - 1) / 2]) {
            swap(data[current], data[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    void search(int value) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == value) {
                cout << "Value found at index: " << i << endl;
                return;
            }
        }
        cout << "Value not found in the heap\n";
    }

    void Deleteroot() {                                      // Time complexity: O(log n)
        if (data.size() == 0) {
            cout << "Heap is empty\n";
            return;
        }
        data[0] = data[data.size() - 1];
        data.pop_back();

        if(!data.empty()) {
            minheapify(0);
        }
    }

    void heapsort(){
        buildMinHeap();
        for(int i = data.size() - 1; i > 0; i--) {
            swap(data[0], data[i]);
            minheapify(0);
        }
    }

};
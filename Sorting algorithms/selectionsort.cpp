#include <iostream>
using namespace std;

void selectionsort(int arr[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        int minindex = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]<arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}


int main(){
    int arr[] = {12, 11, 13, 5, 6};
    selectionsort(arr, 5);
    cout << "Sorted array: ";
    for(int i = 0 ; i<5 ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
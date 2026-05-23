#include <iostream>
using namespace std;

void shellsort(int arr[], int n){
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2){                   // start with big gap then reduce
        for (i = gap; i<n ;i++){
            temp = arr[i];
            int j = i;
            while (j >= gap && arr[j-gap] > temp){           // shift elements to the right until the correct position for temp is found
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main(){
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    shellsort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
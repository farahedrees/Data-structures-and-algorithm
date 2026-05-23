#include <iostream>
#include <vector>
using namespace std;


// sorts halves then merges them together
void merge(vector <int>& arr , int left , int mid , int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    vector<int> L(n1) , R(n2);        // create two temporary arrays to hold the left and right subarrays

    for(int i = 0 ; i < n1 ; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0 ; i < n2 ; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0 , j = 0 , k = left;     // initialize pointers for left and right subarrays and the merged array

    // merging the subarrays
    while (i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements if there are any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}


//splits the array + recursively calls each half + calls the merge function
void mergeSort(vector<int>&arr , int left , int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;     // calculate the middle index
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
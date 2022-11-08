#include <iostream>
using namespace std;

void heap(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int n,i;
    cout<<"Enter number of elements to be sorted: ";
    cin>>n;
    int arr[n];
    cout<<"Enter data in the array :"<<endl;
    for(i=0;i<n;i++)
    cin>>arr[i];

    heapSort(arr, n);
    cout << "Sorted array using heap sort is"<< endl;
    printArray(arr, n);
}


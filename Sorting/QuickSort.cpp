#include<iostream>
using namespace std;

void printArray(int arr[], int size) 
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
 
    cout<<"Pivot: "<<arr[p]<<"\n";
    quickSort(arr, start, p - 1);
    printArray(arr, end+1);

    quickSort(arr, p + 1, end);
}
 
int main()
{
 
    int n, i, swap;
    
    cout<<"N: ";
    cin>>n;

    int arr[n];
    for(i=0; i<n; i++)
    {
        cout<<"Element: ";
        cin>>arr[i];
    }
 
    quickSort(arr, 0, n - 1);
 
    cout<<"\nSorted Array:\n";   
    printArray(arr, n);
 
    return 0;
}
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void inputArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    inputArray(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
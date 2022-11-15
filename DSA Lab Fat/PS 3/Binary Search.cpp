// binary searh
#include <iostream>
using namespace std;

int main()
{
    int n;
    int *arr;
    cout << "Enter number of digits to be sorted: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter the Digits: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0, mid, key;
    int high = n - 1;
    cout << "Enter the key to be searched: ";
    cin >> key;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr[mid])
        {
            cout << "Key found at position " << mid + 1 << endl;
            break;
        }
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low > high)
        cout << "Key not found" << endl;
    return 0;
}
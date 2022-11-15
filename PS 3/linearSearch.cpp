// Linear Search
#include <iostream>
using namespace std;

int main() {
    int n;
    int *arr;
    cout << "Enter number of digits to be sorted: ";
    cin >> n;
    arr = new int[n];

    cout << "Enter the Digits: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int temp;
    cout << "Enter the key to be searched: ";
    cin >> temp;
    for (int i = 0; i < n; i++) {
        if (temp == arr[i]) {
            cout << "Key found at position " << i + 1 << endl;
            break;
        }
        if (i == n - 1)
            cout << "Key not found" << endl;
    }
    return 0;
}
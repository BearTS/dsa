#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k, l, temp, d;
	cout << "Enter number of elements to be sorted : ";
	cin >> n;
	int a[n];
	cout << "Enter data in the array :" << endl;
	for (i = 0; i < n; i++) cin >> a[i];
	d = n / 2;
	for (j = d; j > 0; j = j / 2) {
		if (j % 2 == 0)
			j++;
		for (k = j; k < n; k++) {
			for (l = k - j; l >= 0; l = l - j) {
				if (a[l + j] < a[l]) {
					temp = a[l + j];
					a[l + j] = a[l];
					a[l] = temp;
				} else
                    break;
			}
		}
	}
	cout << "Sorted array using Shell Sort : " << endl;
	for (i = 0; i < n; i++) cout << a[i] << " ";
}
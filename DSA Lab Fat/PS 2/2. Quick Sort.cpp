#include<iostream>
using namespace std;

void quick(int a[50],int left,int right) {
    if(left>=right) return;

    int piv=left;
    int l=left;
    int r=right;

    while(l<r)
    {
        while(a[r]>a[piv])  r--;
        while(a[l]<=a[piv]) l++;
        if(l<r)
        {
            int temp=a[l];
            a[l]=a[r];
            a[r]=temp;
        }
    }
    int temp=a[r];
    a[r]=a[piv];
    a[piv]=temp;
    quick(a,left,r-1);
    quick(a,r+1,right);
}



int main() {
    int n,i;
    cout<<"Enter number of elements to be sorted : ";
    cin>>n;
    int a[n];
    cout<<"Enter data in the array :"<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];

    quick(a,0,n-1);

    cout<<"Sorted array usign Quick Sort : "<<endl;
    for(i=0;i<n;i++) cout<<a[i]<< " ";
}

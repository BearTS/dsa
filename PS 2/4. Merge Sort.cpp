#include<iostream>
using namespace std;

void merge(int a[50],int l,int h,int mid) {
    int i=l,j=mid+1;
    int k=l;
    int temp[50];
    while((i<=mid)&&(j<=h)) {
        if(a[i]<=a[j]) {
            temp[k]=a[i];
            i++;k++;
        } else {
            temp[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid) {
        temp[k++]=a[i++];
    }
    while(j<=h)
        temp[k++]=a[j++];
    for(i=l;i<k;i++)
        a[i]=temp[i];
}


void msort(int a[50],int l,int h) {
    if(l<h) {
        int mid=(l+h)/2;
        msort(a,l,mid);
        msort(a,mid+1,h);
        merge(a,l,h,mid);
    }
}


int main() {
    int n,i;
    cout<<"Enter number of elements to be sorted: ";
    cin>>n;
    int a[n];
    cout<<"Enter data in the array :"<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];
    
    msort(a,0,n-1);

    cout<<"Sorted array using Merge Sort : "<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<< " ";
}

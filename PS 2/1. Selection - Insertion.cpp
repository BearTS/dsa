
#include<iostream>
using namespace std;


int main()
{
    int ch,n,i,j,k,temp,min;
    ch=1;
    cout<<"Enter number of elements to be sorted : ";
    cin>>n;
    int sel[n];
    cout<<"Enter data in the array :"<<endl;
    for(i=0;i<n;i++)
    cin>>sel[i];
    
    while(ch!=0)
    {
    cout << "Enter 1 for Selection Sort" << endl;
    cout << "Enter 2 for Insertion Sort" << endl;
    
    cin>>ch;
    
    switch(ch)
    {
    case 1:
    for(j=0;j<n;j++)
    {
        min=j;
        for(k=j+1;k<n+1;k++)
        {
            if(sel[k]<sel[min])
            min=k;
        }
        temp=sel[j];
        sel[j]=sel[min];
        sel[min]=temp;
    }


     cout<<"Sorted array using Selction Sort : "<<endl;
        for(i=0;i<n;i++)
        cout<<sel[i]<< " ";
        cout << endl;
        break;


    case 2:
    for(j=0;j<n;j++)
    {
       if(sel[j+1]<sel[j])
       {
        temp=sel[j+1];
        for(k=j;k>=0;k--)
        {
            if(sel[k]<temp)
            break;
            else
            sel[k+1]=sel[k];
        }
        sel[k+1]=temp;
       }
    }


     cout<<" Sorted array using Insertion sort : "<<endl;
        for(i=0;i<n;i++)
        cout<<sel[i]<< " ";
        cout << endl;
    break;


    default:
    cout<<"Wrong input"<<endl;
    }
    }
}

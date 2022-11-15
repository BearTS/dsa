#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,i,x,j,sum,c=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    string str,str1,a[n];
    for (i=0;i<n;i++)
        a[i]="Nil";
    for (int i=0;i<n;i++)
    {
        sum=0;
        cout<<"Enter element "<<i+1<<": ";
        cin>>str;
        for(j=0;j<str.length();j++)
        {
            x=str[j]-97;
            sum=sum+x;
        }
        int d=sum%n;
        if (a[d]=="Nil")
            a[d]=str;
        else
        {
            while(a[d]!="Nil")
            {
                d++;
                if (d>=n)
                    d=0;
            }
            a[d]=str;
        }
    }
    cout<<endl<<"The Address array is: "<<endl;
    for (i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Enter search element: ";
    cin>>str1;
    sum=0;
    for(j=0;j<str1.length();j++)
    {
        x=str1[j]-97;
        sum=sum+x;
    }
    int d=sum%n;
    if (a[d]==str1)
        cout<<str1<<" is present directly";
    else
    {
        x=d+1;
        while(x!=d)
        {
            if (a[x]==str1 && x<n)
            {
                c=1;
                break;
            }
            if (x>n)
                x=0;
            x++;
        }
        if (c==1)
            cout<<str1<<" is present";
        else
            cout<<str1<<" is not present";
    }
}

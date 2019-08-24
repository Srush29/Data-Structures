#include<iostream>
using namespace std;

int main()
{

    int a[5], i , j, val;
    int size;
    cout<<"Enter the size of the array";
    cin>>size;
    cout<<"Enter elements of array"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<size;i++)
    {
        val = a[i];
        j = i-1;
        while((j>=0)&&(a[j]>val))
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }

    cout<<"Sorted array : "<<endl;
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}

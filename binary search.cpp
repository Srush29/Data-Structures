#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        int m = (l + h)/2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            h = m - 1;
    }

    return -1;
}

int main()
{
    int t,ch=1;
    cout<<"Enter no.of elements: ";
    cin>>t;
    int arr[t];
    cout<<"\nEnter the Elements: \n";
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    int a;
    while(ch==1)
    {
    cout<<"\nEnter the Element to be searched: "<<"\n";
    cin>>a;
    int result = binarySearch(arr, 0, t-1, a);
    if(result == -1)
    cout<<"\nElement is not found in array\n";
    else
    cout<<"\nElement is present at index \n"<<result;
    cout<<"\nDo you want to search other element: \n1.yes\n0.no";
    cin>>ch;
    }
    return 0;
}

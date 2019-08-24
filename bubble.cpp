#include <iostream>
using namespace std;
class sortval
{
    int arr[100];
    int arr1[100];
    int size;
    int temp1[100],temp2[100];
public:
    void get()
    {
        cout<<"Enter size of array"<<endl;
        cin>>size;
        cout<<"Enter elements to be entered into the array"<<endl;
        for(int i= 0; i<size; i++)
        {
            cin>>arr[i];
            arr1[i] = arr[i];
        }

    }

    void bubble()
    {
        for(int i =0; i<size; i++)
        {
            for(int j = 0; j<size - i - 1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = 0;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            cout<<"Iteration number "<<i+1<<":";
            for(int i =0; i<size;i++)
            {
                cout<<"\t"<<arr[i];
            }
            cout<<endl;
        }

    }

    void display()
    {
        for(int i =0; i<size; i++)
        {
            cout<<"Iteration number "<<i+1<<":";
            for(int i =0; i<size;i++)
            {
                cout<<"\t"<<arr[i];
            }
            cout<<endl;
        }

    }





};

int main()
{
    sortval s;
    s.get();
    s.bubble();
//    s.display();
}

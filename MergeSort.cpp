#include<iostream>
using namespace std;


void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid + 1;
    int n2 =  high - mid;


    int Left[n1], Right[n2];


    for (i = 0; i < n1; i++)
 {

     Left[i] = arr[low + i];

}
    for (j = 0; j < n2; j++)
    {
        Right[j] = arr[mid + 1+ j];

    }

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];

            j++;

        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = Left[i];

        i++;
        k++;

    }

    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;

    }

}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low+(high-low)/2;


        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}


void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<"\t"<<A[i];
}


int main()
{

  int arr_size;

    cout<<"\nEnter the number of elements : ";
    cin>>arr_size;

int arr[30];
    cout<<"\nEnter the elements : "<<endl;
    for(int i =0; i<arr_size; i++)
    {
        cin>>arr[i];
    }


    cout<<"Given array is : "<<endl ;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout<<"\nSorted array is : "<<endl;
    printArray(arr, arr_size);
    return 0;
}

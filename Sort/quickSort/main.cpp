#include <iostream>

using namespace std;

int indexPivot(int arr[], int LB, int UB)
{
    int Start = LB;
    int End = UB;
    int Pivot = UB;

    while(Start < End)
    {
        while(arr[Start] <= arr[Pivot])
        {
            Start++;
        }
        while(arr[End] < arr[Pivot])
        {
            End--;
        }
        if(Start < End)
        {
            swap(arr[Start],arr[End]);
        }
        swap(arr[Pivot],arr[End]);
        return End;
    }
}

int quickSort(int arr[], int LB, int UB)
{
    if(LB < UB)
    {
        int Pivot = indexPivot(arr, LB, UB);
        quickSort(arr, LB, Pivot-1);
        quickSort(arr, Pivot+1, UB);
    }
}

int main()
{
    int arr[] = {20,5,9,8,7};

    cout<<"The unsorted array: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<endl;
    }

    cout<<"The unsorted array: "<<endl;

    quickSort(arr, 0, 4);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

bool binary(int item, int arr[], int Size)
{
    int Start = 0;
    int End = Size-1;

    while(Start<=End)
    {
        int mid = (Start + End)/2;

        if(item == arr[mid])
        {
            cout<<"Item found"<<endl;
            return true;
        }
        if(item < arr[mid])
        {
            End = mid-1;
        }
        else
        {
            Start = mid+1;
        }
    }
    cout<<"Item not found"<<endl;
    return false;
}

int main()
{
    int arr[]={2,6,9,10};
    binary(6, arr, 4);


    return 0;
}

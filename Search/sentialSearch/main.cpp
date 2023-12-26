#include <iostream>

using namespace std;

int sentialLinear(int item, int arr[], int Size)
{
    int last = arr[Size-1];
    arr[Size-1] = item;

    int i=0;
    while(arr[i] != item)
    {
        i++;
    }
    arr[Size-1] = last;
    if((i < Size-1) || (item == arr[Size-1]))
    {
        cout<<"item found: "<<(i+1)<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}

int main()
{
    int arr[]={1,5,20,2};
    sentialLinear(2, arr, 4);
    return 0;
}

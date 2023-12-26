#include <iostream>

using namespace std;

void Merge(int arr[],int Start,int Mid,int End)
{
    int size1=Mid-Start+1;
    int size2=End-Mid;
    int* A1=new int [size1];
    int* A2=new int[size2];
    int i,j;
    for(int i=0;i<size1;i++)
    {
        A1[i]=arr[Start+i];
    }
    for(int j=0;j<size2;j++)
    {
        A2[j]=arr[Mid+1+j];
    }
    i=j=0;
    int k=Start;
    while((i<size1)&&(j<size2))
    {
        if(A1[i]<A2[j])
        {
            arr[k]=A1[i];
            i++;
        }
        else
        {
            arr[k]=A2[j];
            j++;
        }
        k++;
    }
    while (i<size1)
    {
        arr[k]=A1[i];
        k++;
        i++;
    }
    while (j<size2)
    {
        arr[k]=A2[j];
        k++;j++;
    }
}

void MergeSort(int arr[],int Start,int End)
{
    if(Start<End)
    {
        int Mid=(Start + End)/2;
        MergeSort(arr,Start,Mid);
        MergeSort(arr,Mid+1,End);
        Merge(arr,Start,Mid,End);
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

    MergeSort(arr, 0, 4);
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}

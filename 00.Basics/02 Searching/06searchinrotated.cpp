#include<iostream>
using namespace std;

int pivot(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    while(s<e)
    {
        int mid = s+(e-s)/2;
        if(arr[mid]>=arr[0])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int search2(int arr[], int s, int e, int key){
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(key == arr[mid])
        {
            return mid;
        }
        else if(key > arr[mid])
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return -1;
}

int main()
{
    int nooftests;
    cout<<"Enter the number of test cases: ";
    cin>>nooftests;
    for(int i=1; i<=nooftests; i++){
        cout<<"testcase #"<<i<<endl;
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        int rotated[n];
        cout<<"Enter the values: "<<endl;
        for(int j=0; j<n; j++){
            cin>>rotated[j];
        }
        int key;
        cout<<"Enter key: ";
        cin>>key;
        int index_pivot = pivot(rotated, n);
        if(key > rotated[n-1]){
            cout<<"Index of the key in given array is: "<<search2(rotated, 0, index_pivot-1, key)<<endl;
        }
        else
        {
            cout<<"Index of the key in given array is: "<<search2(rotated, index_pivot, (n-1), key)<<endl;
        }
    }
    return 0;
}
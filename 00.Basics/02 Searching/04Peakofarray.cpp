#include<iostream>
using namespace std;

int peak(int arr[], int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        int mid;
        mid = s + (e-s)/2;
        if(arr[mid]<arr[mid+1])
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

int main(){
    int no_test;
    cout<<"Enter the no. of test cases: ";
    cin>>no_test;
    for(int i=1; i<=no_test; i++)
    {
        cout<<"testcase #"<<i<<endl;
        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        int arr[n];
        cout<<"values: "<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<"The peak of value of the array is at index: "<<peak(arr,n)<<endl;
    }
    return 0;
}
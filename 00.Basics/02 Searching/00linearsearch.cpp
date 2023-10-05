#include<iostream>
using namespace std;

int linearSearch(int n, int arr[], int key)      // Time Complexity O(n)
{
    for(int j=0; j<n; j++)
    {
        if(arr[j]== key){
            return j;
        }
    }
    return -1;
}

Input
/*
int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<linearSearch(n, arr, key);
    return 0;
}*/
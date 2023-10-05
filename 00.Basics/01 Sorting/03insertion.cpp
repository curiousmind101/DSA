#include<iostream>
using namespace std;

int main()
{
    //Input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)      
    {
        cin>>arr[i];
    }
    //**********************************

    // Main Algorithm                                          
    for(int i=0; i<n; i++){      // Time Complexity O(n^2)
        int temp = arr[i];
        int j=i-1;
        while(temp < arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
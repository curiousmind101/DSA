#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int ans = -1;
    int s =0; 
    int e =n-1;
    while(s<=e)
    {
        int mid;
        mid= s + (e-s)/2;
        if(arr[mid]==key){  
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid]<key){
            s = mid +1;
        }
        else{
            e = mid-1; 
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int ans = -1;
    int s =0; 
    int e =n-1;
    while(s<=e)
    {
        int mid;
        mid= s + (e-s)/2;
        if(arr[mid]==key){  
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]<key){
            s = mid +1;
        }
        else{
            e = mid-1; 
        }
    }
    return ans;
}

int main()
{
    int no_test;  //Number of test cases
    cout<<"Enter the number of test Cases: ";
    cin>>no_test;
    for(int i=1; i<=no_test; i++)
    {
        cout<<"testcase #"<<i<<endl;
        int n; //size of the array
        cout<<"Enter the size of the array: ";
        cin>>n;
        int numbers[n];
        for(int i=0; i<n; i++){
            cin>>numbers[i];
        }
        int key;
        cin>>key;
        cout<<"First Occurrence of the key at index: "<<firstOcc(numbers, n, key)<<endl;
        cout<<"Last Occurrence of the key at index: "<<lastOcc(numbers, n, key)<<endl;
    }
    return 0;
}
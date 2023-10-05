#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int key){      // Time Complexity O(log(n)) base 2
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid;
        mid = s + (e-s)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){
    int no_test;
    cin>>no_test;
    for(int i=1; i<=no_test; i++)
    {
        int n;
        cin>>n;
        int array[n];
        for(int i=0; i<n; i++)
        {
        cin>>array[i];
        }
        int key;
        cin>>key;
        cout<<binarysearch(array, n, key)<<endl;
    }
    return 0;
}
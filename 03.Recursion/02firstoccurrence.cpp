#include<iostream>
using namespace std;

int firstoc(int arr[], int size, int key){
    if(size==0){
        return -1;
    }
    if(arr[0]==key){
        return 0;
    }
    int ans = firstoc(arr+1, size-1, key);
    if(ans == -1){
        return -1;
    }else{
        return (ans+1);
    }
}

int firstOcr(int arr[], int size, int key){
    int ans = -1;
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            ans = i;
            break;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<firstoc(arr, n, key);
    return 0;
}
#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int *temp = new int[high-low+1];

    while(i <= mid && j<=high){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high){
    if(high==low){
        return;
    }

    int mid = (high+low)/2;      //to divide array into two parts
    mergeSort(arr, low, mid);    //calling merge sort on first parts
    mergeSort(arr, mid+1, high); //calling merge sort on second part
    merge(arr, low , mid, high); //merge these two sorted parts
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
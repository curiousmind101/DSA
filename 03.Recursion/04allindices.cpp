#include<bits/stdc++.h>
using namespace std;

void indices(int arr[], int size, int key, int d[], int & count){
    if(size == 0){
        return;
    }
    indices(arr, size-1, key, d, count);
    if(arr[size-1]==key){
        d[count++] = size-1;
    }
    return;
}

//Method-2
void indices2(int arr[], int size, int key, int d[], int &count, int &c){

    if(size == 0){
        return;
    }
    indices2(arr+1, size-1, key, d, count, c);
    if(arr[0] == key){
        d[count++] = c;
    }
    c++;
    return;
}


// Method-3

int indices3(int arr[], int size, int key, int d[]){  // No Extra Space for Count variable
    if(size == 0){
        return 0;
    }
    int ans = indices3(arr, size-1, key, d);
    if(arr[size-1]==key){
        d[ans] = size-1;
        return ans+1;
    }
    return ans;
}

//Iterative method

int* indices4(int arr[], int size, int key, int d[]){
    if(size == 0){
        return 0;
    }
    int count = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            d[count++] = i;
        }
    }
    return d;
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
    int d[n];
    int count = 0;
    //indices(arr, n, key, d, count);
    int c=0;
    //indices(arr, n, key, d, count, c);
    count = indices3(arr, n, key, d);
    for(int i = 0; i<count; i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
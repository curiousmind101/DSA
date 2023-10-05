#include <bits/stdc++.h>
using namespace std;

// Run in CMD  
int fibbonaccir(int n){        // Brute Force
    if(n<=1){
        return n;
    }
    int a=fibbonaccir(n-1);
    int b=fibbonaccir(n-2);
    return a+b;
}

int fibbonacci(int n, int *arr){     //Memorization
    if(n <= 1){    //base case
        return n;
    }
    //check data
    if(arr[n] != -1){
        return arr[n];
    }
    int a = fibbonacci(n-1, arr);
    int b = fibbonacci(n-2, arr);
    //save
    arr[n] = a+b;
    return arr[n];
}
int fibbonacci(int n){ 
    int arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    return fibbonacci(n, arr);
}


int fibbonaccidp(int n){            //DP approach
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main(){
    int n;
    cin>>n;
    cout<<fibbonacci(n);
}
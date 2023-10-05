#include<iostream>
using namespace std;

int printfibbo(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return (printfibbo(n-1)+printfibbo(n-2));
}


int main(){
    int n;
    cin>>n;
    cout<<printfibbo(n);
    return 0;
}
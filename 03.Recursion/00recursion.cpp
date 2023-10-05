#include<iostream>
using namespace std;

int recur(int n){
    if(n == 0){
        return 1;
    }else{
        return n*recur(n-1);
    }
}


int main(){
    int n;
    cin>>n;
    cout<<recur(n);
    return 0;
}
#include<iostream>
using namespace std;


//Brute Force
int ManipulateSetBit(int n){
    if(n&1){
        return(n^1);
    }
    int i = 1;
    while(!(n&(1<<i))){
        i++;
    }
    return (n^(1<<i));
}
int main(){
    int n;
    cin>>n;
    cout<<ManipulateSetBit(n);
    return 0;
}
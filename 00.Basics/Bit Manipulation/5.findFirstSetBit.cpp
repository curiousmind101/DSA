#include<iostream>
using namespace std;


//Brute Force
int firstSetBit(int n){
    if(n&1){
        return 1;
    }
    int i = 1;
    while(!(n&(1<<i))){
        i++;
    }
    return (1<<i);
}
int main(){
    int n;
    cin>>n;
    cout<<firstSetBit(n);
    return 0;
}
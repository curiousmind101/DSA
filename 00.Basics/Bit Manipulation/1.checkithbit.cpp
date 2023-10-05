#include<iostream>
using namespace std;

// if ith bit is 1 then it is "set".
// if ith bit is 0 then it is "unset".

int main(){
    int n, i;
    //cin>>n>>i;        want to use this then open in terminal
    //for now,
    n = 6;
    //i = 3;              //result - unset  as 6 - 00000110
    i = 2;                //result - set
    if(n&(1<<i)){
        cout<<"set\n";
    }else{
        cout<<"unset\n";
    }
    return 0;
}
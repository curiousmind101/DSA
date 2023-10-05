#include<iostream>
using namespace std;

//flip/invert the ith bit as 1->0 or 0->1 without changing any other bit.

int main(){
    int n, i;
    //cin>>n>>i;    for user use

    //for now,

    n = 6, i=5;                  //6 - 00000110
    cout<<(n^(1<<i));            //new n - 00100110 = 38
    return 0;
}
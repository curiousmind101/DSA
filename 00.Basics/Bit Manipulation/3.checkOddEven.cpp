#include<iostream>
using namespace std;


//Check whether number is odd or even

int main(){
    int x, y, n;
    //let x = 6 and y = 9 
    x = 6, y = 9;

    //cin>>x>>y;    //for user 

    //Ordinary way

    if(x%2 == 0){
        cout<<"x is Even\n";
    }else{
        cout<<"x is Odd\n";
    }


    //By Bit Manipulatiion
    //for x
    if(x&1){
        cout<<"x is Odd\n";
    }else{
        cout<<"x is Even\n";
    }

    //for y
    if(y&1){
        cout<<"y is Odd\n";
    }else{
        cout<<"y is Even\n";
    }

    n = 10;
    return 0;
}
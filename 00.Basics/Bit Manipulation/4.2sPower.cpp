#include<iostream>
using namespace std;

//Check Whether number is 2s Power or not

//Brute Force
void TwosPower(int n){
    while(n%2==0){
        n/=2;
    }
    if(n==1){
        cout<<"yes 2s power\n";
    }else{
        cout<<"not 2s power\n";
    }
}

void TwosPowerBits(int n){
    if(!(n&(n-1))){                           //0 - false for if  but it means 2s power
        cout<<"yes 2s power\n";
    }else{
        cout<<"not 2s power\n";
    }
}

int main(){
    int n, m;
    //cin>>n;    //for user 

    //for now, 
    n = 16, m = 10;

    TwosPower(n);
    TwosPower(m);

    TwosPowerBits(n);
    TwosPowerBits(m);

    
    return 0;
}


#include<iostream>
using namespace std;

int increament(int n){    //function with normal argument
    n++;
    return n;
}

int increamentr(int & s){   //function with reference argument
    s++;
    return s;
}

/* 

int* pointerfn(int t){
    int a = t;
    return &a;    **bad practice because the variable int a will be destroyed after the fn's execution
}
*/

/* 
int & referencefn(int m){
    int w = m;
    return w;     **bad practice because the variable int w will be destroyed after the fn's execution
}
*/

int main(){
    int i = 5;
    cout<<i<<"\n";
    int j = i;  //only copies the value
    cout<<j<<"\n";
    j++;        //j's value will increase but not of i
    cout<<i<<"\n";
    int &k = i; //takes i's refference. means both k & i are the variables of same memory location 
                //ex - a person with two names
                /*imp - its necessary to give an initializer to a reference variable and it can not
                be used to point other variable later*/
    k++; 
    cout<<i<<"\n";

    //with functions
    increament(i);  //this will not increase i's value
    cout<<i<<"\n";
    increamentr(i); //this will increase i's value
    cout<<i<<"\n";
    
    /*int*ptr = pointerfn(i);
    int&ref = referencefn(i);*/  //part of bad practice
    
    return 0;
}
#include<iostream>
#define PI 3.14
using namespace std;

//int a;   -> Global Variable - All function in the file can access this.

int main(){
    //suppose you have to write a formula that is area of a circle pi*r^2
    //options to write pi 
    //1 put direct value 3.14
    double r = 5;
    cout<<3.14*r*r<<"\n"; //but it will be hard to change in all places wherever you have used it. 
    //(for ex. upto 4 dcmls in place of 2 dcmls)
    //2 define a variable which contains value of pi now it will become easier to change every where;
    double pi = 3.14;
    cout<<pi*r*r<<"\n"; //but it wil take a memory and you have to take risk if someone just changed it later in code bymistake.
   
    //so the best option is #define 
    //it replaces all the the word with defined value at before compilation and doesen't take any memory.

    cout<<PI*r*r<<"\n"; //best method


    // same lecture
    // global variable /_!_\warning never use a global variable its a bad practice 
    return 0;
}
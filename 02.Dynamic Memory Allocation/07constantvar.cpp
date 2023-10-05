#include<iostream> 
using namespace std;

//only path become constant, not the memory

int main(){
    int p =5; //normal variable 
    p = 6;    //and can be changed letter on

    int const n = 6;
    // n = n+8;   -- Error
    //n++; also gives an error | you can not change a constant intger's value | read only

    int t = 6;    
    int const &k = t;  //now k is the reference variable to constant integer 
                       //from this, the path through k to the memory become constant
    //k++;             //this will give an error ie. read only access , you can not write at the memory location | read only
    //but you can still modify the value at the memory through t like t++; or t=12; or t = t+12;

    int const a = 5;  //imp - needs a initializer always  ****************

    //a++; this will give an error because the variable a is not modifiable | read only
    //int &k = n; error you can not change const int's value through a non const refernce variable
    int const &k = a; // k is reference variable of constant integer | you promised to compiler that you will not change the value
    //k++; error | read only

    int d = 4; 
    int c = 5;
    int const* z = &d; //z is a pointer of constant integer
    //you can do d++;
    //you can not do (*z)++; ie. the path through *z   is blocked, you can read only.
    //but you can do this
    z = &c;  //the path from z to d is constant not the z

    int e =10;
    int f=12;
    int * const ptr = &e; //now the ptr is constant pointer to an integer 
    //(*p)++; error
    //ptr = &f; //it can not refer to other variable

    int const u = 10;
    int const *v = &u; 
    //u++; error
    //(*v)++; error

    int const l = 11;
    //int * j = &l; error | you have to promise them that will not change the value later
    //for that you need to make a pointer which points to constant integer
    int const *j = &l;
    return 0;
}
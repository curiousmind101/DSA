#include<bits/stdc++.h>
using namespace std;

//Lecture -13 constant function
/*
A function can be defined as constant function if and only if 
the function won't change the value of a "this" variable.

A function qualifies to become a const function if this will not 
change any memeber attribute through itself.

*/
class fraction{
    private:
    int numirator;
    int denominator;
    public:
    fraction (){
        //default constructor
    }
    fraction(int numirator, int denominator){
        this -> numirator = numirator;
        this -> denominator = denominator;
        simplify();
    }
    void print() const{  //here function is a constant function i.e. 
                         //you can't change the values of data members using this function.
        cout<<numirator<<"/"<<denominator<<"\n";
    }

    void simplify(){
        int gcd = 1;  //greatest common divisor
        int n = min(this -> denominator, this -> numirator);

        for(int i=1; i<n; i++){
            if(this -> denominator%i == 0 && this -> numirator%i ==0){
                gcd = i;
            }
        }
        this->denominator = denominator/gcd;
        this->numirator=numirator/gcd;
    }

    //sec = second variable
    void add(fraction const &sec){  //void add(fraction const &sec) const{   it will give an error in the next line where we will change the value of "this"
        int lcm = denominator*(sec.denominator);
        this -> numirator = numirator*(sec.denominator) + sec.numirator*denominator;
        this -> denominator = lcm;
        simplify();
        //basically it is this->simplify();
    }

    void multiply(fraction const &sec){
        this->numirator = numirator*(sec.numirator);
        this->denominator = denominator*(sec.denominator);
        simplify();
    }
};

int main(){

    fraction const f1;
    //Now you can't call any function for f1 untill and unless the function is a const function
    fraction f2;
    //you can call any of the function for f2, either it is a constant function or non-constant
    return 0;
}
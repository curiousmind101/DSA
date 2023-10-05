#include<bits/stdc++.h>
using namespace std;

//Lecture-8 Fraction Class
class fraction{
    private:
    int numerator;
    int denominator;
    public:
    fraction (){
        //default constructor
    }
    fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
        simplify();
    }
    void print() const{  //here function is a constant function i.e. you can't change values of data members using this.
        cout<<numerator<<"/"<<denominator<<"\n";
    }

    void simplify(){
        int gcd = 1;  //greatest common divisor
        int n = min(this -> denominator, this -> numerator);

        for(int i=1; i<n; i++){
            if(this -> denominator%i == 0 && this -> numerator%i ==0){
                gcd = i;
            }
        }
        this->denominator = denominator/gcd;
        this->numerator=numerator/gcd;
    }

    //sec = second variable
    void add(fraction const &sec){
        int lcm = denominator*(sec.denominator);
        this -> numerator = numerator*(sec.denominator) + sec.numerator*denominator;
        this -> denominator = lcm;
        simplify();
        //basically it is this->simplify();
    }

    void multiply(fraction const &sec){
        this->numerator = numerator*(sec.numerator);
        this->denominator = denominator*(sec.denominator);
        simplify();
    }

    //Operator Overloading
    fraction operator+(fraction const &sec) const{ 
        int lcm = denominator*(sec.denominator);
        int num = numerator*(sec.denominator) + (sec.numerator)*denominator;
        fraction ans(num, lcm);
        return ans;
    }
    fraction operator*(fraction const &sec) const{
        int num = numerator*sec.numerator;
        int deno = denominator*(sec.denominator);
        fraction ans(num, deno);   //no need to simplify again it is simplified when created
        return ans;
    }
    fraction operator/(fraction const &sec) const{
        int num = numerator*(sec.denominator);
        int deno = denominator*(sec.numerator);
        fraction fnew(num, deno);  //no need to simplify again it is simpliefied when created
        return fnew;
    }

    bool operator==(fraction const &f2) const{
        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
    }

    //pre increament
    fraction & operator++(){
        numerator = numerator+denominator;
        simplify();
        return *this;
    }

    //post increament - nesting is not allowed - jhanjhat khatam
    fraction operator++(int){
        fraction fnew(numerator,denominator);
        numerator += denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
    //nesting eg. - ++(++i);

    
    fraction & operator+=(fraction const &sec){
        int lcm = denominator*(sec.denominator);
        int num  = numerator*(sec.denominator) + (sec.numerator)*denominator;
        denominator = lcm;
        numerator = num;
        simplify();
        return *this;
    }

    fraction & operator-=(fraction const &sec){
        int lcm = denominator*(sec.denominator);
        int num = numerator*(sec.denominator) - (sec.numerator)*denominator;
        denominator = lcm;
        numerator = num;
        simplify();
        return *this;
    }
};

int main(){
    /*fraction f1(25, 18);
    fraction const f2(10, 25);
    cout<<"f1: ";
    f1.print();

    cout<<"f2: ";
    f2.print();

    fraction f3(3, 5);

    cout<<"f3: ";
    f3.print();

    //exp-start
    cout<<"f1 after f1+f3: ";
    f1.add(f3);
    f1.print();

    f3.add(f2);  //changing f3 //can not change directly because members are private
    cout<<"f1 after changing f3: ";
    f1.print();
    //exp-end
    //Conclusion - so there won't be any effect of change in f3, on f1.

    //f2.multiply(f3); can't do because f2 is a constant variable


    fraction s(1, 5);  //this sec variable and the sec variable in class function
                         //will be considered different
    //multiply
    //sec = 1/5 and f3 = 3/5
    s.multiply(f3);
    s.print();
    //problem - not getting simplified.*/

    //experiment
    fraction f1(5, 1);
    f1.print();

    //without &
    //1.
    // ++f1;   
    // f1.print();
    // //2.
    // ++(++f1);
    // f1.print();

    // //3.
    // fraction f3 = ++(++f1);
    // f3.print();

    //with &
    //1.
    // ++f1;
    // f1.print();
    //2.
    // ++(++f1);
    // f1.print();
    //3.
    // fraction f3 = ++(++f1);
    // f3.print();

    //conclusion - put "&" in function while creating, reason - buffer memory
    return 0;
}
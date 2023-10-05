#include <iostream>
using namespace std;

/*
compile time polymorphism
1. function overloading eg. int set() , int set(int x, int y), int set(int x, int y, int z)
2. operator overloading eg. +, += in complex number class
3. function overriding eg. both parent and child class have same function
*/

//over riding
class Vehicle{  
    private:
       int maxSpeed;
    protected:
       int numTyres;
    public:
       string color;
    Vehicle(){   //defualt constructor   
        cout<<"constructor vehicle"<<endl;
    }

    Vehicle(int z){ //para constructor
       maxSpeed = z;
    }

    virtual void print(){  
        cout<<"Vehicle"<<endl;
    }

    virtual void print1() = 0;  //pure virtual function //now this class is abstract
};

class Car : virtual public Vehicle{
    public:
    int numGers;
    Car(){   //calling Vehicle's default constructor implicitely
       cout<<"constructor car"<<endl;
    }

    Car(): Vehicle(3){

    }

    void print(){  //function overriding
        cout<<"main to car hu";
    }

    void print1(){
        cout<<"virtual function"<<endl;
    }
}; 

int main(){
    //Vehicle v;  //commmented due to pure virtual function you can use it with removing pure virtual function
    Car c;

    //v.print();
    c.print();

    //Vehicle* v2 = new Vehicle;
    //v2->print();

    Vehicle *v3 = &c;    //Car * c3 = &v is not possible 
    //v2->print();  //output - vehicle
    v3->print(); // output - vehicle
    //because the v3 pointer has access of only vehicle class
    //doesn't matter to which class's object(child/parent) it is pointing to. 

    //compile time polymorphism

    //for run time polymorphism in overiding use virtual infront of base class function

    //after this v3-> will call print() of class whichever it is pointing to.

    //if you remove car class print() function it will call vehicle class print() fucntion

    //if you remove virtual void print it will through error for v3->print();

    //use case employee base,  child engineer, manager, general staff salary calculation
    //array of employees

    //pure virtual function 
    //class becomes adhura 
    
    //now object of vehicle class can not be made

    //child car has two options - 
    //1. khud abstract ban jaye
    //2. define that pure virtual function


    return 0;
}
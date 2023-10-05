#include<iostream>
using namespace std;
class Vehicle{  
    private:
       int maxSpeed;
    protected:
       int numTyres;
    public:
       string color;
    Vehicle(){   //defualt constructor

    }

    Vehicle(int z){ //para constructor
       maxSpeed = z;
    } 

};
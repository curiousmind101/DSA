#include <iostream>
using namespace std;

//Note derived class can not call base class's constructor if it is private or protected
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

    void print(){
        cout<<"Vehicle"<<endl;
    }
};

class Car : virtual public Vehicle{
    public:
    int numGers;
    Car(){   //calling Vehicle's default constructor implicitely
       cout<<"constructor car"<<endl;
    }

    Car(): Vehicle(3){

    }

    void print(){
        cout<<"main to car hu";
    }
};

class Truck: virtual public Vehicle{

    public:
    Truck(){
        cout<<"constructor truck"<<endl;
    }

    Truck():Vehicle(4){

    }
};

class Bus : public Truck, public Car{
    public:

    Bus(){
        cout<<"constructor Bus"<<endl;
    }

    Bus(): Vehicle(5){

    }
};


int main(){
    Bus b;

    //b.print();  //are vhai par kaun sa wala truck-vehicle ya car

    b.Car::print(); //car wala print call hoga
    b.Truck::print(); //vehicle wala print call hoga kyoki truck k pass print funciton hai hi nahi
    //b.Vehicle::print(); yerorr because vehicle is grand parent

    //but still there is a problem that bus class have two copeis of vehicle class
    //solution- virtual

    //in case of virtual grand child can call grand parent functions

    Bus bnew;
    //final value of bus will be 5as buss class consturctor will be called in the last


    return 0;
}
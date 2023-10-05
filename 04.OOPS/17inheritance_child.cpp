#include "16inheritanc_base.cpp"

//Note - private member of base class cannot be inheritade **

class Car : public Vehicle{
    private:


    protected:
    //base class's protected members will be here


    public:
    //base class's public members will be here
    int numGers;
    
    Car(){   //calling Vehicle's default constructor implicitely

    }

    Car() : Vehicle(5){ //necessary to pass argument when default constructor is not there

    }

    Car(int x): Vehicle(x){ //if we want x from user end

    }

    Car(int x, int y): Vehicle(x){ //its upon vehicles constructor how many arguments it requires

    }
    void print(){
        cout<<"NumTyres: " << numTyres<<endl;
        cout<<"Color: " << color <<endl;
        cout<<"NumGears: " <<numGers<<endl;
        //cout<<"MaxSpeed: " << maxSpeed<<endl; -> this will give error as it is inaccesible

    }

};

class Bike: protected Vehicle{
    private:

    protected:
    //base class's both  public* and protected* members will be here

    public:

};

class Truck: private Vehicle{
    private:
    //base class's both  public* and protected*  members will be here

    protected:

    public:
};
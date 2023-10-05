#include<bits/stdc++.h>
using namespace std;

class students{
    private:
    public:
    int age;
    char *name;


    //Lecture-4  //Constructor 

    //1. Same name as class. eg. given below
    //2. No return type
   
    //Working   
    //When you define an object (eg. students s1), the default contructor is called ( as s1.student(); )
    
    //default constructor
    //there is also an inbuilt default constructor 
    //once we create a constructor, the inbuilt one won't be available for us
    students(){ 
        cout<<"Default Constructor";
        //No input Arguments.
        //created automatically when you define a class
        //no need to create explicitely
    }

    //parameterized Constructor - Takes Arguments
    students(int a){
        age = a;
    }

    /*
    once you create a parameterized constructor, you won't be able to
    create a new variable without required varibale. If you want to create 
    a new variable without passing any value you need to create a default type
    constructor.
    */

    //constructors will be called according to..
    //1. number of arguments 
    //2. type of arguments 

    // students(int cc):classcode(cc){
    //     //Initialization list
    //     //It is called at the time of creation of an object and useful to set const data members.
    // }

    /*
    students(int cc, int zc): classcode(cc), zebracode(zc) {  //for multiple const variable

    }
    */

    students(int age, char *name){    //multiple - parameterised constructor
        this -> age = age;            //contructor-3
        this -> name = name; 
    }

    //Lecture -5 

    //Inbuilt Constructors and destructors

    //copy constructor
    // This constructor is called whenever you copy an object to another. ex - students s3(s4); OR ex - students s3 = s4;
    // ** A default copy constructor does shallow copy.

    //Destructor
    //1. Same name as our class
    //2. No return type
    
    //default destructor
    //3. No input arguments.
    //4. No need to create
    ~students(){
        //default destructor
    }
    //now the default destructor will no longer be availble

    //** Note - any destructor dosen't call for dynamic allocations

    //you need to deallocate explicitely the dynamic memory

};

int main(){

    //Lecture - 4
    //default constructor will be called
    students s1;      
    students *s2 = new students;

    //parameterised constructor will be called
    students s3(20);  
    students *s4 = new students(30);

    //constructor-3 will be called
    students s5(20, "Bandar");
    students *s6 = new students(21, "Doge");

    //Note - As soon as you create a new constructor whether it is default type or 
    //       parameterized, inbuilt will won't be accesible

    // so after deleting the default type constructor that we created,
    // whenever we define a object like eg. students s7; will give error
    // now we have to pass data according to availbale constructors

    //Lecture - 5
    students s7(s1);  // Once you create your own copy constructor it will be unavailble

    students s8(*s2); //dereffering the variable is important

    students *s9 = new students(s3);

    students *s10 = new students(*s4);

    //you can use = operator too, to copy 

    students s11 = s7;   //this is actually --> students s11(s7);
    students *s13 = new students; 
    *s13 = *s6;   //copy the values

    students *s14 = new students;

    s14 = s2;     //copy the address


    //to deallocate memory for dynamic object
    delete s2;
    delete s4;
    delete s6;
    delete s9;
    delete s10;
    //now the destructor will be called for above objects

    return 0;
}   //from here destructor will be called for all the static memory allocation
    //because it is the end of scope for all objects.
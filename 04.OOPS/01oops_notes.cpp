#include<bits/stdc++.h>
using namespace std;

//A class is a blueprint() for the object /  prototype of an object

//Lecture 1  Defining Class

class students{           

//Lecture 2  Access modifiers 
//Access modifiers are used to implement an important 
//aspect of Object-Oriented Programming known as Data Hiding.
    private:              // Default modifier
    int rollnumber;       // Accessible under class only

    protected:            //similar to private 
    int marks;            //The difference is that the class members declared as Protected can be
                          // accessed by any subclass (derived class) of that class as well. 

                          //Note: This access through inheritance can alter the access modifier of 
                          //the elements of base class in derived class depending on the mode of Inheritance.

    public:               // Accessible from everywhere. Even from outside the class
    int age;
    char *name;

    //Lecture 3   Getters and Setters
    void setdata(int r){  //setter to set values of data members of the class
    rollnumber = r;
    
    }

    int getroll(){        //getter to get values of data members of the class
    return rollnumber;
    }

    
    // Constructor

    students(){       //called everytime whenever an object is created.
                      //a function with same name as class **no need to write return type.
                      //this is a default constructor with no parameters.
    cout<<"Default constructor is called"<<endl;
    }

    //Distructor
    ~students(){          //called everytime whenever the scope of an object ends.
    cout<<"Default distructor is called"<<endl;
    }

};  //semicolon at the end is important

int main(){

    //static
    students s1;
    students s2 , s3;
    s1.setdata(25);
    s1.age = 20;
    char mainname[] = "Vaman";
    s1.name = mainname;

    //dynamic
    students *s4 = new students;  //similar to int *ptr = new int;

    (*s4).age = 23;               //similar to *ptr = 23;  or pr.first , pr.second
    s4->age = 23;                 //-> is used for pointers to access directly
                                  //-> does same work as (*s4).age

    cout<<"rollnumber: "<<s1.getroll()<<endl;
    cout<<"age: "<<s1.age<<endl;
    cout<<"name: "<<s1.name<<endl;
    return 0;
}
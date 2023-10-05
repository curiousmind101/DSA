#include<bits/stdc++.h>
using namespace std;


//Lectrue 10 Shallow Copy and Deep Copy

class students{
    private:
    public:
    int age;
    char *name;

    students(int age, char *name){    //multiple Argument - parameterised constructor
        this -> age = age;            //contructor-3
        //shallow copy 
        //this -> name = name;        // "this" keyword points to the data member of current object.
                                      // basically "this" is a pointer which holds the address of current object. 
        
        //deep copy
        this -> name = new char[strlen(name)+1];  //created new memory in heap
        strcpy(this -> name, name);               //copying the data 
    }

    //Lecture-11  //Copy Constructor

    // This constructor is called whenever you copy an object to another. ex - students s3(s4); OR ex - students s3 = s4;
    // ** A default copy constructor does shallow copy.

    //explicit copy constructor -  inbuilt won't be available from now on
    students (students const &s){  //due to const we can not change the value of 'this->' object through s
        this -> age = s.age;         //using &(reference variable) to save memory and also to stop infinte loop of copying.
        //shallow copy 
        //this-> name = s.name;
        
        //deep copy 
        this -> name = new char[strlen(s.name)+1];  //1 extra space for null character
        strcpy(this -> name, s.name);
    }
    void display(){
        cout<<age<<" "<<name<<"\n";
    }


    //Static Data Members 

    /*It belongs to the whole class and same for the each object of an class.
    static int totalstudents;
    students(){
        totalstudents++;
    }*/
};

//int students :: totalstudents = 0;

int main(){

    /*  To check deep copy and shallow copy

    char name[] = "Kishlay";
    students s1(25 , name);
    name[0] = 'B';
    students s2(28 , name);
    s1.display();
    s2.display();
    s1.display();
    students s3(s1);
    s3.name[3] = 's';
    s3.display();
    s1.display();*/
    return 0;
}
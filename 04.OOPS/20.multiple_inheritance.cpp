#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
      void print(){
        cout<<"Student"<<endl;
      }

      string name;
};

class Teacher{
    public:
      void print(){
        cout<<"Teacher"<<endl;
      }

      string name;
};

class TA: public Teacher, public Student{
    public:
    //    void print(){
    //     cout<<"TA"<<endl;
    //    }
    //    string name;
};

int main(){
    TA a;
    //a.print();  //when print function is availble in TA class it will call that one
                //but will give error when TA doesn't have print() function as both
                //student and teacher class have print() function
                //:: scope resolution
    a.Teacher::print(); //need to specify which print() you want use
    a.Student::print();  

    //similarly 
    a.Teacher::name = "dronacharya";
    a.Student::name = "arjun";
    //a.name = "xyz"; //error
}
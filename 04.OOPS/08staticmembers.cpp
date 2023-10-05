#include<bits/stdc++.h>
using namespace std;


//Lecture 14 Static Members

//Static Members are the globale members that are common for all the objects of any class
//eg- for a classroom the number of students present in a class will be common for all the students
class students{
    public:
    int age;
    char *name;

    static int totalstudents;  //Sarvjanik Property //not a private property
    //this property doesn't get copied for every object
    students(){
        totalstudents++;
    }

    //static function
    static int getRollnumber(){
        return totalstudents;
    }
    //can only be used to access a static data member
    //this function don't have "this"
};

int students :: totalstudents = 0;

int main(){
    students s1;
    //cout<<s1.totalstudents<<endl;  logically incorrect
    students s2, s3;
    cout<<students::totalstudents<<endl;//in this way you can access the static property
    //will output 3
    cout<<students::getRollnumber<<endl;
    //will output 3
    return 0;
}
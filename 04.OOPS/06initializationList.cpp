#include<bits/stdc++.h>
using namespace std;


//Lecture - 12 Initialization List

class students{
    int const score;
    public:
    int const classcode;
    int age;
    char *name;

    /*  
    students(int score, int cc, int age, char* name){
        this->score = score;
        this->classcode = cc;
        this->age = age;
        this->name = name;
    }
    This too isn't going to work because the score and classcode variable be already created
    */

   //the solution is
    students(int score, int cc, int age, char* name): score(score), classcode(cc){
        this->age = age;
        this->name = name;
    }
};

int main(){
    
    return 0;
}
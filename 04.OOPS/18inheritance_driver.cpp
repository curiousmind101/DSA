#include "19grandchild.cpp"

int main(){
    Vehicle v;

    v.color = "Blue";
    //v.maxSpeed = 100; //inaccessible - private member
    //v.numTyres = 4;   //inaccessible - protected member

    Car c;
    c.color = "Black";
    c.numGers = 4;
    //c.numTyres = 4; //inaccessible - accible only inside child class

    HondaCity h;  //default construcotr 

    HondaCity h(5);  //when default constructor of car class will not be there;

    HondaCity h(4, 5);

    //types of inheritence 

    //1. single inheritance
         /*   A
              |
              v
              B
         */

    //2. multilevel inheritance
        /*  A
            |
            v
            B
            |
            v
            C
        */

    //3. Hirarchical   eg. family

       /*        A
              /  |  \
             B   C   D
            /
            E   
       */

    //4. Multiple inheritance  eg. PhD scholar or Teaching Assistant
       /*    A   B  C
              \  |  /
                 D
       
       */  //explained - 20.multiple inheritance


    return 0;
}

/*
Order of calling the constructor for above 
1. Vehicle default constructor - for object v
2. Vehicle dfault constructor through car class - for object c
3. Car's default constructor - object c
4. Car's destructor object - c 
5. Vehicle destructor through car class - object - c 
6. Vehicle destructor object - v
*/

/*

*/
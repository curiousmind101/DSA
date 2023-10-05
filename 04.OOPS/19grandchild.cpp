#include "17inheritance_child.cpp"


class HondaCity : public Car{
    public:
       HondaCity(){
        cout<<"HondaCity constructor"<<endl;
       }

       HondaCity(int x): Car(x){

       }

       HondaCity(int x, int y) : Car(x, y){

       }
       //Hondacity can call Vehicle's constructor directly
       //Hirarchy

       ~HondaCity(){
        cout<<"HondaCity constructor"<<endl;
       }
};
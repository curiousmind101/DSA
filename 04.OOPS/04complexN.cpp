#include<bits/stdc++.h>
using namespace std;
//Lecture 9 Complex Numbers
class complexn{
    public:
    int real;
    int img;
    complexn(int real, int img){
        this->real = real;
        this->img = img;
    }
    void print(){
        cout<<this->real;        //Showing error but there is no problem
        if(img > 0){
            cout<<"+"<<this->img<<"i";
        }else{
            cout<<this->img<<"i";
        }
        // if(img<0){
        //     cout<<"-j"<<(-1)*img;
        // }else{
        //     cout<<"+j"<<img;
        // }
    }
    void add(complexn const &c2){
        this -> real = real+c2.real;
        this -> img = img + c2.img;
    }
    void multiply(complexn const &c2){
        int temp = real;
        this -> real = real*c2.real + (-1)*img*c2.img;
        this -> img = temp*c2.img + img*c2.real;
    }
};

int main(){
    complexn c1(3,-64);
    complexn c2(4,50);
    c1.add(c2);

    c1.print();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class plate{
    public:
    int data;
    plate *previous;
    plate(int data){
        this -> data = data;
        previous = NULL;
    }
};

class Stack{
    public:
    plate *lastplate;
    int size;
    Stack(){
        lastplate = NULL;
        size = 0;
    }

    plate push(int data){
        plate *newplate = new plate(data);

        if(lastplate == NULL){
            lastplate = newplate;
        }else{
            newplate->previous = lastplate;
            lastplate = newplate;     
        }
        size++;
    }

    plate pop(){
        plate *temp = lastplate;
        lastplate = lastplate->previous;
        delete temp;
        size--;
    }

    int top(){
        return lastplate->data;
    }

    bool empty(){
        if(lastplate == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int givesize(){
        return size;
    }
};

plate* reverseastack(plate * top){
    if(top == NULL || top->previous == NULL){
        return top;
    }

    plate * reversed  = reverseastack(top->previous);
    plate * bottom = top->previous;
    bottom->previous = top;
    top->previous = NULL;
    return reversed;
}


int main(){
    Stack s1;
    s1.push(5);
    s1.push(10);
    s1.push(20);
    s1.push(45);

    plate * topnew = s1.lastplate;
    Stack s2;
    s2.lastplate = reverseastack(topnew);
    cout<<s2.top()<<endl;
    s2.pop();
    cout<<s2.top()<<endl;


    /*s1.pop();
    cout<<s1.top()<<endl;
    if(s1.empty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    s1.pop();
    s1.pop();
    s1.pop();
    if(s1.empty()){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }*/
    return 0;
}
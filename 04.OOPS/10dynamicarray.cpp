#include<bits/stdc++.h>
using namespace std;

//Similar to vector
class dynamicArray{
    int *data;
    int index;
    int capacity;
    public:
    dynamicArray(){
        data = new int[1];
        index = 0;
        capacity = 1;
    }
    void add(int element){
        if(index == capacity){
            int *newdata = new int[2*capacity];
            for(int i=0; i<index; i++){
                newdata[i] = data[i];
            }
            capacity *= 2;
            newdata[index++]=element;
            delete [] data;
            data = newdata;
        }
        else{
            data[index++]=element;
        }
    }
    
    
    dynamicArray (dynamicArray const &d) {
        //Shallow copy 
        //this -> data = d.data;
        //deep copy
        this -> data = new int[d.capacity];
        for(int i=0; i<d.index; i++){
            this -> data[i] = d.data[i];
        }
        this-> index = d.index;
        this-> capacity = d.capacity;
    }

    // copy using = operator
    void operator=(dynamicArray const &d){
        //Shallow copy 
        //this -> name = name;
        this -> data = new int[d.capacity];
        for(int i=0; i<d.index; i++){
            this -> data[i] = d.data[i];
        }
        this-> index = d.index;
        this-> capacity = d.capacity;
    }

    //printing all elements
    void printall(){
        for(int i=0; i<index; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    //returns capacity of the object
    int getcapacity(){
        return capacity;
    }

    //returns value of index in array;
    int get(int i){
        if(i<index){return data[i];}
        else{return -404;}
    }

    //sets/changes value at given index
    void set(int i, int change){
        if(i<capacity){
            data[i] = change;
        }else if(i == capacity){
            add(change);
        }
        else{return;}
    }
    int size(){
        return index;
    }
};
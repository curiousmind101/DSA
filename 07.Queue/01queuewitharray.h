#include<bits/stdc++.h>
using namespace std;
template <typename T>

class queuewitharray{
    T *data;
    int first;
    int last;
    int capacity;
    int size;
    public:
    queuewitharray(){
        data = new T[1];
        first = -1;
        last = 0; //this shows the index after the last 
        size = 0;
        capacity = 1;
    }
    /*queuewitharray(int cap){
        data = new T[cap];
        first = -1;
        last = 0; //this shows the index after the last 
        size = 0;
        capacity = cap;
    }*/

    //lecture 3 queue
    void push(T x){
        if(size == capacity){
            T* newData = new T[2*capacity];

            for(int i=0; i<capacity; i++){
                newData[i] = data[first%capacity];
                first++;
            }
            first = 0;
            last = capacity; //this should be written before updating capacity
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[last] = x;
        last = (last+1)%capacity;

        if(first == -1) first = 0;
         
        size++;
    }

    /* //created dynamic that's why 
    void add(T x){
        //lecture 2 queue
        if(size == capacity){
             cout<<"full"<<endl; return;
        }

        data[last] = x;
        last = (last+1)%capacity;

        if(first == -1) first = 0;
         
        size++;
    }*/

    T pop(){
        if(empty()){
            cout<<"queue is emepty";
            return 0;
        }
        T ans = data[first];
        first = (first+1)%capacity;
        size--;
        return ans;
    }

    T front(){
        if(empty()){
            cout<<"queue is emepty"<<endl;
            return 0;
        }
        return data[first];
    }

    bool empty(){
        return (size == 0);
    }

    int getsize(){
        return size;
    }

    void emplace(int ex){
        data[last-1] = ex;
    }
};
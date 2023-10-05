#include<iostream>
using namespace std;

//stack Implementation using array
template<typename T>
class stack{
    T *data;
    int size=0;
    int capacity;
    int nextIndex;

    public:

    stack(){
        capacity = 0;
        size = 0;
        nextIndex = 0;
    }

    void push(int n){
        if(size == 0){
            data = new T[1];
            data[nextIndex] = n;
            capacity = 1;
            
        }else if(nextIndex == capacity){
            T *newData = new T[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;

            delete [] data;
            data = newData;
            data[nextIndex] = n;
        }else{
            data[nextIndex] = n;
        }
        nextIndex++;
        size++;
    }

    //int pop()  bbad mein bana lena for dynamic stack


    /* stack with fixed capacity
    stack(int capacity){   //asking capacity is must if you are implementing stack with array of fixed size
        this->capacity = capacity;
        data = new T[capacity];
        size = 0;
        nextIndex = 0;
    }

    void push(int n){    //not dynamic
        if(nextIndex == capacity){
            cout<<"stack overflow";  //if stack is dynamic it will never through overflow
            return;
        }

        data[nextIndex] = n;
        nextIndex++;
        return;
    }
    */

    int pop(){
        if(size == 0) return INT32_MIN;
        int ans = data[nextIndex-1];
        nextIndex--;
        size--;
        return ans;
    }

    int top(){
        if(size == 0) return INT32_MIN;

        return data[nextIndex-1];
    }

    int printsize(){
        return nextIndex;
    }

    bool isEmpty(){
        return (nextIndex == 0);
    }

    int printcapacity(){
        return capacity;
    }
};

int main(){
    stack<int> s;
    if(s.isEmpty()) cout<<"empty"<<endl;
    else cout<<"not empty"<<endl;

    s.push(5);
    cout<<s.printsize()<<endl;
    cout<<s.pop()<<endl;
    s.push(6);
    cout<<s.top()<<endl;
    s.push(7);
    s.push(8);
    cout<<s.printcapacity()<<endl;
    return 0;
}
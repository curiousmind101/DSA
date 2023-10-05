#include<iostream>
using namespace std;

int main(){
    /*int n; // this defines a variable in stack memory | Hear you know the memory location by variable's name
    cin>>n;
    int arr1[n];  //1.this will take memory at runtime| you don't know what value a user can give 
                  //stack start with a small size memory, show this can be a problem at runtime
    int arr2[100];//ye wala point utna khas nahi laga phir bhi likh dete hain
    int k;
    cin>>k;
    for(int i=0; i<k; i++){  //now hear you don't know the value of k which will be given by the user
        cin>>arr2[i];        //and this could be less than 100 or greater than 100
    }                        //if k is less than the 100 then rest cells will be waste
                             //and if this is greater than the 100 it can not take upto that*/

    //Introducing The dynamic memory - Heap
    new int;         //this is useless. because you don't know the location of memory
    int*p = new int; //so now you can use pointer p to use the allocated memory
    cout<<p<<"\n";

    delete p;   //Important - It is very important to delete the allocated memory in heap.
    
    
    //For Array
    //for an array in stack memory we should know the size of the array at compile time not at the runtime because..
    //the user can give a large size at the runtime that is a concern for the stack memory. 
    /*ie. int arr[10000000000]; is ok | but cin>>k;  int arr[k]; is not a good thing if k is a large value, 
     because stack starts with a small value by default if size is not specified.*/
    //int k;
    //cin>>k;
    //int*ptr = new int[k];
    int*ptr = new int[10];
    for(int i=0; i<5; i++){  //this will take all 5 values and rest values are by default 0
        cin>>ptr[i];
    }
    for(int i=0; i<10; i++){
        cout<<ptr[i]<<" "<<(ptr+i)<<"\n";
    }                       
    delete [] ptr;          // syntax for array.
    cout<<ptr<<" ";
    return 0;
}
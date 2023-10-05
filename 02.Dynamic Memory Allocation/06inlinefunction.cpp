#include<iostream>
using namespace std;

int maximum(int a, int b);   
int minimum(int a, int b);

inline int maximum2(int a, int b);
inline int minimum2(int a, int b);

int main(){
    int a, b;
    a = 6;
    b = 9;
    //for max;
    int max = (a>b) ? a : b;
    //for min;
    int min = (a>b) ? b : a;

    // but in case of we need to find multiple times min/max we can't write this ("(a>b) ? b : a;") heavy syntax all the time.
    // An Alternative is we can define a function that does the same;
    //cout<<maximum(a,b);   // Advantage - Improved Readibility
    //cout<<minimum(a,b);   // Disadvantage - Decreased performance

    //Best Alternative is Inline Function
    //Inline function
    cout<<maximum2(a,b);
    cout<<minimum2(a,b);
    // Every time I call these function this don't call and wait it will just paste the code inside the function and perform at the place



    return 0;
}

int maximum(int a, int b){
    return (a>b) ? a : b;
}
int minimum(int a, int b){
    return (a>b) ? b : a;
}

inline int maximum2(int a, int b){
    return (a>b) ? a : b;
}

inline int minimum2(int a, int b){
    return (a>b) ? b : a;
}
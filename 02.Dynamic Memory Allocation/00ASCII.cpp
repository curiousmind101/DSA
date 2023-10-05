#include<iostream>
using namespace std;

int main(){

    cout<<(char)('A'+ ('B'-'A'))<<endl;  // 'B'-'A' will give an integer (interchanged value assigned by ASCII)
    char space = ' ';                    //  ASCII - American Standard Code for Information Interchange
    cout<<(char)35<<" "<<endl;           //  explicitly defining that it is a 'char' type data 
    cout<<('B'-'A')<<endl;               //  Algebric Operation on 'char' data will give integer interchanged value | prints 1
    int difference = ('c'-'a') ;         //  'c'-'a' = 2 | simple
    cout<<difference<<endl;              //  output will be 2
    cout<<2<<endl;                       //  output will be 2
    return 0;

}

// For more details https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

//  OR https://ascii.cl/
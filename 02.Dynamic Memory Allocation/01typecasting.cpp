#include<iostream>
using namespace std;


//compiler can directly asign a value to a char variable without ' ' cotation.  eg. - cin>>variable;
//but whenever we have to assign to a char variable we have to put ' ' cotation.
//Note: cin>>(char) can assign without ' '.  Reff. - point 1
int main(){
    int i = 65;
    char c = i;           //this read it as ASCII character means (char)65 = 'A'. | information interchanged.
    int *p = &i;          //implicit typecast | i's address assigned to p
    int **pc = &p;        //double pointer    | p's address assigned to pc
    int *n = p;           //n = p | char *pch = p; gives error || because of different data types
    
    char *pch = (char*)p; //explicit typecast | assigns *p value as bit address | big endians | 
                          //reads only first bit from left
    cout<<i<<"\n";        //prints i's value
    cout<<c<<"\n";        //prints c's value (A) | ASCII reading
    cout<<p<<"\n";        //prints i's address
    cout<<&p<<"\n";       //prints p's address
    cout<<pc<<"\n";       //prints p's address
    cout<<*pc<<"\n";      //prints i's address
    cout<<**pc<<"\n";     //prints i's value
    cout<<n<<"\n";        //prints i's address (same as p)
    **pc = 5;             //assigning value to i | and *pc = int/char/float is invalid
    cout<<pch<<"\n";      //prints enq
    cout<<*(pch)<<"\n";   //prints enq
    return 0;
}
#include<iostream>
using namespace std;

class newvariable{
    public:
    int intdata;
    char chardata;
    double doubledata;
    void function(){

    }
};

int main(){
    int i = 5;                // i is an integer variable having value 5;
    int *pi = &i;             // pi is a pointer, pointing to an integer variable;
    // You can also do 
    cout<<i<<endl;            // prints value of i as it is 5;
    cout<<pi<<endl;           // prints address of i in Hexadecimals;
    cout<<*pi<<endl;          // * is called dereffernce operator // it extracts the value stored at the address
    // i++;  OR (*pi)++; both are same;


    char c = 'A';             // c is a char varibale;
    char *pc = &c;            // pc is a pointer, pointing to a char variable;

    double d = 5.254;         // d is a double variable;
    double *pd = &d;          // pd is a pointer, pointing to a double variable;

    float f = 5.23;           // f is a float variable;
    float *pf = &f;          // pf is a pointer, pointing to a float variable; 

    newvariable newvar;       // new is a newvariable variable / object;
    newvariable * newpptr = &newvar;  // newptr is a pointer, pointing to a newvariable type variable;

    // **** Important
    // Never keep a pointer open/free, always asign a value to a pointer. for eg. int *p;
    // If you keep a pointer open it will point to a random variable of your memory a can manipulate important data; **
    // In case you you don't know what to assign, just assign a NULL to it as int *p = 0; OR int *p = NULL;

    // Pointers in Case of Array 
    int arr[5];
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }
    int *ptr = arr;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" "<<arr+i<<"\n";  //arr+i access location of the ith box from 0 index
        //ptr++;                         //only ptr++; is possible, ptr+integer (ptr+i)  | increament and decreament only make sense in case of arrays
        cout<<*(ptr+i)<<endl;            //*(ptr + i) or *(arr+i) prints value stored in cell | in case of value ptr+i is possible
    }                                    // ** same rules for string
    return 0;
}
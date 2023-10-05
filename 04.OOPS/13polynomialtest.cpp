#include "11polynomial.cpp"

int main(){
    Polynomial p1;
    p1.add(0, 25);
    p1.add(5, -14);
    p1.printfun();
    cout<<p1.getcapacity()<<endl;

    Polynomial p2;
    p2.add(3, 20);
    p2.add(4, 14);
    p2.printfun();
    cout<<p2.getcapacity()<<endl;

    p1*=p2;
    p1.printfun();

    p1+=p2;
    p1.printfun();

    /*Polynomial p3 = p1+p2;
    p3.printfun();
    cout<<p2.getcapacity()<<endl;

    Polynomial p4 = p1-p2;
    p4.printfun();
    cout<<p2.getcapacity()<<endl;

    p4.add2c(9, 5);
    p4.printfun();

    Polynomial p5;
    p5=p1*p2;
    //p5.add2c(1, 10);
    //p5.add2c(64, 10);
    //p5.add2c(64, 5);
    cout<<p5.getcapacity()<<endl;
    p5.printfun();*/

    /*
    Polynomial p1;
    p1.add(2, 6);
    p1.add(4, 12);
    p1.printfun();

    Polynomial p2;
    p2.add(5, 10);
    p2.add(8, -3);
    p2.printfun();
    p1.printfun();*/
    return 0;
}
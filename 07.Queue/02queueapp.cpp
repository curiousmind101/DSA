#include "01queuewitharray.h"
#include <queue>

int main(){
    queuewitharray<int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    
    cout<<q.front()<<"\n";
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    cout<<q.getsize()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}
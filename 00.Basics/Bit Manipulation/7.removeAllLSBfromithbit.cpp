#include<iostream>
using namespace std;

int removeAllLSBfromithbit(int n, int i){
    int m = ~((1<<(i+1))-1);
    return m&n;
}

int removeAllRSBfromithbit(int n, int i){
    int m = ((1<<(i))-1);
    return m&n;
}
int main(){
    int n, i;
    cin>>n>>i;
    cout<<removeAllLSBfromithbit(n, i)<<endl;
    cout<<removeAllRSBfromithbit(n, i)<<endl;
    return 0;
}
#include "bstclass.cpp"

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(40);
    b.print();
    // if(b.hasData(3)){
        // cout<<"Found"<<endl;
    // }else{
        //cout<<"Not Found"<<endl;
    // }
    b.deletenode(20);
    cout<<endl;
    b.print();
    return 0;
}
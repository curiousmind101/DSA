#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
template <typename T>

class binarytreenode{
    public:
    T data;
    binarytreenode<T>* left;
    binarytreenode<T>* right;
    binarytreenode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~binarytreenode(){
        delete left;
        delete right;
    }
};
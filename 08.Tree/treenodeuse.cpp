#include "treenode.h"
using namespace std;

void printtree(treenode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<(root->data)<<":";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printtree(root->children[i]);
    }
}

int main(){
    treenode<int>* root = new treenode<int>(10);
    treenode<int>* Node1 = new treenode<int>(20);
    treenode<int>* Node2 = new treenode<int>(30);
    root->children.push_back(Node1);
    root->children.push_back(Node2);
    treenode<int>* Node3 = new treenode<int>(40);
    treenode<int>* Node4 = new treenode<int>(50);
    Node1->children.push_back(Node3);
    Node2->children.push_back(Node4);
    printtree(root);
    return 0;
}
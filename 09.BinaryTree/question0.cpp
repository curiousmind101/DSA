#include "binarytreenode.h"

binarytreenode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter root data: ";
    cin>>rootdata;
    cout<<"\n";
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){

        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        cout<<"Enter "<<front->data<<"'s Left Child: ";
        int left;
        cin>>left;
        if(left != -1){
            front->left = new binarytreenode<int>(left);
            pendingnodes.push(front->left);
        }else{
            front->left = NULL;
        }
        
        cout<<"Enter "<<front->data<<"'s Right Child: ";
        int right;
        cin>>right;
        if(right != -1){
             front->right = new binarytreenode<int>(right);
             pendingnodes.push(front->right);
        }else{
            front->right = NULL;
        }
    }
    return root;
}


//Question 00
binarytreenode<int>* duplicatenode(binarytreenode<int>* node){
    if(node == NULL){
        return NULL;
    }
    node->left = duplicatenode(node->left);
    node->right = duplicatenode(node->right);
    binarytreenode<int>* newnode = new binarytreenode<int>(node->data);
    newnode->left = node->left;
    node->left = newnode;
    return node;
}

void printlevelwise2(binarytreenode<int>* root){
    if(root == NULL){
        return;
    }
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    
    while(pendingnodes.size() != 0){
        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        if(pendingnodes.size() == 0){
            break;
        }
        if(front != NULL){
            cout<<front->data<<" ";
            if(front->left != NULL){
                pendingnodes.push(front->left);
            }
            if(front->right != NULL){
            pendingnodes.push(front->right);
            }
        }else{
            cout<<"\n";
            pendingnodes.push(NULL);
        }
    }
    cout<<"\n";
}

/*int main(){
    binarytreenode<int> * root = takeinputlevelwise();
    printlevelwise2(root);
    binarytreenode<int>* node = duplicatenode(root);
    printlevelwise2(node);
    return 0;
}*/
#include "01bst.h"

class BST{
    binarytreenode<int>* root;
    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }

    private:

    binarytreenode<int>* findrightmin(binarytreenode<int>* node){
        if(root == NULL){
            binarytreenode<int>* newnode = new binarytreenode<int>(INT32_MAX);
            return newnode;
        }

        binarytreenode<int>* ans = findrightmin(node->left);
        
        if(ans->data < node->data){
            return ans;
        }else{
            return node;
        }
    }

    binarytreenode<int>* deletenode(int data, binarytreenode<int>* node){
        if(node == NULL){
            return NULL;
        }
        else if(data<node->data){
            node->left = deletenode(data, node->left);
        }else if(data> node->data){
            node->right = deletenode(data, node->right);
        }else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }else if(node->left == NULL){
                binarytreenode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else if(node->right == NULL){
                binarytreenode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                binarytreenode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deletenode(rightMin, node->right);
                return node;
            }
        }
    }
    binarytreenode<int>* insert(int data, binarytreenode<int>* node){
        if(node == NULL){
            binarytreenode<int>* newnode = new binarytreenode<int>(data);
            return newnode;
        }
        if(data < node->data){
            node->left = insert(data, node->left);
        }else{
            node->right = insert(data, node->right);
        }
        return node;
    }
    bool hasData(int data, binarytreenode<int>* node){
        if(node == NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }

        if(data < root->data){
            return hasData(data, node->left);
        }else{
            return hasData(data, node->right);
        }
    }
    public:
    void print(){
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
    }
    void deletenode(int data){
       root = deletenode(data, root);
       return;
    }

    void insert(int data){
        if(root == NULL){
            binarytreenode<int>* newnode = new binarytreenode<int>(data);
            root = newnode;
            return;
        }
        if(data < root->data){
            root->left = insert(data, root->left);
        }else{
            root->right = insert(data, root->right);
        }
        return;
    }

    bool hasData(int data){
       return hasData(data, root);
    }
};
#include "question0.cpp"

//Question 02
int findlca(binarytreenode<int>* root, int n1, int n2){
    if(root == NULL){
        return -1;
    }
    //case 1 root == n1 || n2
    if(root->data == n1 || root->data == n2){
        return root->data;
    }

    int l = -1, r = -1;
    if(n1 < root->data || n2 < root->data){
        l = findlca(root->left, n1, n2);
    }
    if(n1 > root->data || n2 > root->data){
        r = findlca(root->right, n1, n2);
    }

    //case2 
    if(l != -1 && r != -1){
        return root->data;
    }
    //case3
    if(l != -1){
        return l;
    }else if( r != -1){
        return r;
    }
    return -1;
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    int n1, n2;
    cin>>n1>>n2;
    cout<<findlca(root, n1, n2);
    return 0;
}
#include "question0.cpp"

void baby(binarytreenode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k<0){
        return;
    }
    if(k == 0){
        cout<<root->data<<"\n";
        return;
    }
    baby(root->left, k-1);
    baby(root->right, k-1);
    return;
}
int find(binarytreenode<int>* root, int node, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        baby(root->left, k-1);
        baby(root->right, k-1);
        return 1;
    }
    int l = find(root->left, node, k);
    
    if(l != -1){
        if(k-l == 0){
            cout<<root->data<<endl;
        }
        baby(root->right, k-l-1);
        return l+1;
    }
    int r = find(root->right, node, k);
    if(r != -1){
        if(k-r == 0){
            cout<<root->data<<endl;
        }
        baby(root->left, k-r-1);
        return r+1;
    }
    return -1;
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    cout<<"\n";
    int node, k;
    cin>>node>>k;
    find(root, node, k);
    return 0;
}
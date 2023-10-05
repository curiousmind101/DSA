#include "question0.cpp"

int replacer(binarytreenode<int>* root, int add){
    if(root == NULL){
        return 0;
    }
    int temp = root->data;
    int r = replacer(root->right, add);
    if(add != 0){
        root->data += (add+r);
    }else{
        root->data += r;
    }
    int l = replacer(root->left, temp+r);
    return temp+r;
}

void replacewithsum(binarytreenode<int>* root){
    replacer(root, 0);
    return;
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    replacewithsum(root);
    printlevelwise2(root);
}
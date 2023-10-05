#include "question0.cpp"

void helper(binarytreenode<int>* root, int k, vector<int> s, int sum){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        if(sum+root->data == k){
            s.push_back(root->data);
            for(int i=0; i<s.size(); i++){
                cout<<s[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    s.push_back(root->data);
    sum += root->data;
    helper(root->left, k, s, sum);
    helper(root->right, k, s, sum);
    return;
}

void pathsumk(binarytreenode<int>* root, int k){
    vector<int> v;
    helper(root, k, v, 0);
    return;
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    int k;
    cin>>k;
    pathsumk(root, k);
    return 0;
}
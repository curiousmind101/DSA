#include "question0.cpp"

void makevector(binarytreenode<int>* root, vector<int>& v){
    if(root == NULL){
        return;
    }
    makevector(root->left, v);
    v.push_back(root->data);
    makevector(root->right, v);
    return;
}

void printpairsum(binarytreenode<int>* root, int sum){
    vector<int> v;
    makevector(root, v);

    int i=0, j=v.size()-1;
    while(i<j){
        if(v[i]+v[j] == sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        if(v[i]+v[j] > sum){
            j--;
        }else{
            i++;
        }
    }
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    int s;
    cin>>s;
    printpairsum(root, s);
    return 0;
}
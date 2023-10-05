#include "question0.cpp"


//Question 1
int heightofthenode(binarytreenode<int>* root, int node){
    if(root == NULL){
        return INT32_MIN;
    }
    if(root->data == node){
        return 1;
    }
    int l = heightofthenode(root->left, node);
    if(l != INT32_MIN){
        return l+1;
    }
    int r = heightofthenode(root->right, node);
    if(r != INT32_MIN){
        return r+1;
    }
    return INT32_MIN;
}

void cousin(binarytreenode<int>* root, int p, int q){
    int h1 = heightofthenode(root, p);
    int h2 = heightofthenode(root, q);
    if(h1 == h2){
        cout<<"true";
    }else{
        cout<<"false";
    }
}


//Question 2

pair<int, stack<int>> helper(binarytreenode<int>* root){
    pair<int, stack<int>> p;
    if(root == NULL){
        p.first = INT32_MIN;
        stack<int> s;
        p.second = s;
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        p.first = 1;
        stack<int> s;
        s.push(root->data);
        p.second = s;
    }
    pair<int, stack<int>> l = helper(root->left);
    pair<int, stack<int>> r = helper(root->right);
    if(l.first > r.first){
        l.second.push(root->data);
        l.first += 1;
        return l;
    }else{
        r.second.push(root->data);
        r.first += 1;
        return r;
    } 
}

void longestpath(binarytreenode<int>* root){
    pair<int, stack<int>> ans = helper(root);
    while(ans.second.size() != 0){
        cout<<ans.second.top()<<endl;
        ans.second.pop();
    }
}




int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    /*question1
    int p, q;
    cin>>p>>q;
    cousin(root, p, q);
    */
    
    longestpath(root);

    return 0;
}
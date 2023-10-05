#include "question0.cpp"


class Answer{       ////Check BST - Aam Zindagi | Search for mentos zindagi if you can
    public:
    int mini;
    int maxi;
    bool itis;
    int h;
};
Answer largestbst(binarytreenode<int>* root){
    Answer ans;
    if(root == NULL){
        ans.itis = true;
        ans.mini = INT32_MAX;
        ans.maxi = INT32_MIN;
        ans.h = 0;
        return ans;
    }
    Answer l = largestbst(root->left);
    Answer r = largestbst(root->right);
    
    ans.itis = ((l.maxi < root->data && r.mini >= root->data) && l.itis && r.itis);
    ans.mini = min(root->data,min(r.mini,l.mini));
    ans.maxi = max(max(r.maxi, l.maxi), root->data);
    if(ans.itis){
        ans.h = 1+max(l.h, r.h);
    }else{
        ans.h = max(l.h , r.h);
    }
    return ans;

}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    cout<<largestbst(root).h;
    return 0;
}
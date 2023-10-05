#include "question0.cpp"
//Question 01
int helppairsum(binarytreenode<int>* root, int diff){
    if(root == NULL){
        return INT32_MAX;
    }
    if(root->data == diff){
        root->data = INT32_MIN;
        return diff;
    }
    int lans = helppairsum(root->left, diff);
    int rans = helppairsum(root->right, diff);
    if(lans == diff){
        return lans;
    }else{
        return rans;
    }
}

void printpairsum(binarytreenode<int>* root, binarytreenode<int>* node, int s){
    if(root == NULL){
        return;
    }
    if(node == NULL){
        return;
    }
    if(node->data != INT32_MIN){
        int diff = s-(node->data);
        int ans = helppairsum(root, diff);
        if(ans == diff){
            if(node->data < diff){
                cout<<node->data<<" "<<ans<<endl;
            }else{
                cout<<ans<<" "<<node->data<<endl;
            }
        }
    }
    printpairsum(root, node->left, s);
    printpairsum(root, node->right, s);
    return;
}


//nlogn
/*void convertBTtoArr(BinaryTreeNode<int> *root , vector<int> &output)
{
 if(root==NULL)
     return;
    
    output.push_back(root->data);
    convertBTtoArr(root->left,output);
    convertBTtoArr(root->right,output);
    
    
}
void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    vector<int> output;
    convertBTtoArr(root,output);
    sort(output.begin(),output.end());
    
    int i=0,j=output.size()-1;
    
    while(i<j)
    {
        
        if(output[i]+output[j]==sum)
        {
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
        
        else if(output[i]+output[j]>sum)
        {
            j--;
        }
        else
        {
            i++;
        }    
    }   
}*/
int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    int s;
    //cin>>s;
    printpairsum(root, root, 15);
    return 0;
}
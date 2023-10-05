#include<iostream>
#include "treenode.h"
using namespace std;

// // Print tree depth first ////////////Recursion is used//Also two independent loops are used //////////////////
void printree(treenode<int>* root){            
    if(root == NULL){
        return;
    }

    cout<<root->data<<":"; //1st loop for printing
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<"\n";

    for(int i=0; i<root->children.size(); i++){  //2nd loop for calling recursion
        printree(root->children[i]);
    }
}

// // Print tree breadth first //////////No Recursion is used, Operate with 2 loops ///////////////////////////////
void printreelevelwise(treenode<int>* root){   
    if(root == NULL){
        return;
    }
    queue<treenode<int>*> pendingnodes;

    pendingnodes.push(root); 

    while(pendingnodes.size() != 0){    //first loop(while) to operate queue , 

        treenode<int>* front = pendingnodes.front(); //don't forget to store in front and pop it
        pendingnodes.pop();

        cout<<front->data<<": ";   //front data
        for(int i=0; i<front->children.size(); i++){   //2nd loop to print children and  to push them in queue
            treenode<int>* child_data = front->children[i];
            cout<<child_data->data<<", ";
            pendingnodes.push(child_data);
        }
        cout<<"\n";
    }
}

// // Count Nodes ///////////////////////////////////////////////////////////////////////////
int countnode(treenode<int>* root){       
    if(root->children.size() == 0){  //a node with no child
        return 1;
    }

    int ans = 1;  //count the node itselft
    for(int i=0; i<root->children.size(); i++){
        ans += countnode(root->children[i]);  //recursive call to count it's children
    }
    return ans;
}


// // Sum of all Nodes //////////////////////////////////////////////////////////////////////
int sumofallnodes(treenode<int>* root){
    if(root->children.size() == 0){
        return root->data;
    }
    int ans = root->data;
    for(int i=0; i<root->children.size(); i++){  //recursive call inside loop
        ans += sumofallnodes(root->children[i]);
    }
    return ans;
}

// // Find Largest Element in tree ///////////////////////////////////////////////////////
treenode<int>* largest_element(treenode<int>* root){
    if(root->children.size() == 0){
        return root; 
    }
    treenode<int>* largest;
    largest = root;
    for(int i=0; i<root->children.size(); i++){ //recursive call inside loop
        treenode<int>* largestinChildren = largest_element(root->children[i]);
        if( largestinChildren->data > largest->data){
            largest = largestinChildren;
        }
    }
    return largest;
}

// // Take input Level wise //////////////////////////////////////////////////////////////////
treenode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<" Enter root Data: ";
    cin>>rootdata;
    treenode<int>* root = new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes;

    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        int numchild;
        cout<<"Enter number of childs of: "<<front->data<<endl;
        cin>>numchild;
        for(int i=0; i<numchild; i++){
            int child_data;
            cout<<"Enter the data of "<<(i+1)<<"th child"<<endl;
            cin>>child_data;
            treenode<int>* child = new treenode<int>(child_data);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

// // Take input // Depth First /////////////////////////////////////////////////////////////
treenode<int>* takeinput(){
    cout<<"Enter data"<<endl;
    int rootdata;
    cin>>rootdata;
    treenode<int> * root = new treenode<int>(rootdata);
    int n;
    cout<<"Enter No. of children of "<<rootdata<<": ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter data of "<<i+1<<"th child of "<<rootdata<<endl;
        treenode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

// //Finding Tree's Height ////////////////////////////////////////////////////////////////

int tree_height(treenode<int>* root){
    if(root->children.size() == 0){
        return 1; 
    }
    int highest = 1;
    for(int i=0; i<root->children.size(); i++){
        int child_height = tree_height(root->children[i])+1;
        if(child_height>highest){
            highest = child_height;
        }
    }
    return highest;
}

// // Find depth of a Node ////////////////////////////////////////////////////////////////

int depth_of_node(treenode<int>* root, int node){
    if(root->data == node){
        return 0;
    }
    if(root->children.size() == 0){
        return -1;
    }
    int ans = 0;
    for(int i=0; i<root->children.size(); i++){
        int ans = depth_of_node(root->children[i], node);
        if(ans != -1){
            return ans+1;
        }
    }
    return ans;
}

// // Count Leafs of a tree ////////////////////////////////////////////////////////////////

int leafs_of_tree(treenode<int>* root){
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i=0; i<root->children.size(); i++){
        int small = leafs_of_tree(root->children[i]);
        ans += small;
    }
    return ans;
}

// // Print all nodes at level K //////////////////////////////////////////////////////////
void printatlevelK(treenode<int> * root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<", ";
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        printatlevelK(root->children[i], k-1);
    }
}

// // Reverse Print // Leafs First ///////////////////////////////////////////////////////////
void reverseprint(treenode<int>* root){
    if(root == NULL){
        return;
    }
    if(root->children.size() == 0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        reverseprint(root->children[i]);
    }
    cout<<root->data<<" ";
}

// //delete a tree //////////////////////////////////////////////////////////////////////////
void deletetree(treenode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        deletetree(root->children[i]);
    }
    delete root;
}

// ///////////////////////////////////////////////////////////////////////////////////////////
int main(){
    treenode<int> *root = takeinputlevelwise();
    /*printreelevelwise(root);
    cout<<countnode(root)<<endl;
    cout<<sumofallnodes(root)<<endl;
    treenode<int>* largest = largest_element(root);
    cout<<largest->data<<endl;
    cout<<tree_height(root)<<endl;
    int node;
    cout<<"Enter Node to find: "<<endl;
    cin>>node;
    cout<<depth_of_node(root, node)<<endl;*/
    int k; 
    //cin>>k;
    //cout<<" Number of Leafs: "<<leafs_of_tree(root)<<endl;
    //cout<<" Nodes at Level k: ";
    //printatlevelK(root, k);
    reverseprint(root);
    deletetree(root);
    reverseprint(root);
    //printreelevelwise(root);
    return 0;
}
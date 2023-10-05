#include "01bst.h"

binarytreenode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"Enter root data: ";
    cin>>rootdata;
    cout<<"\n";
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){

        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        cout<<"Enter "<<front->data<<"'s Left Child: ";
        int left;
        cin>>left;
        if(left != -1){
            front->left = new binarytreenode<int>(left);
            pendingnodes.push(front->left);
        }else{
            front->left = NULL;
        }
        
        cout<<"Enter "<<front->data<<"'s Right Child: ";
        int right;
        cin>>right;
        if(right != -1){
             front->right = new binarytreenode<int>(right);
             pendingnodes.push(front->right);
        }else{
            front->right = NULL;
        }
    }
    return root;
}

void printlevelwise2(binarytreenode<int>* root){
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

binarytreenode<int>* searchthekey(binarytreenode<int>* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    binarytreenode<int> * ans;
    if(key < root->data){
        ans = searchthekey(root->left, key);
    }
    else{
        ans = searchthekey(root->right, key);
    }
    return ans;
}

void findthekey(binarytreenode<int> * root, int key){
    binarytreenode<int> * location = searchthekey(root, key);
    if(location != NULL){
        cout<<"Found : location data: "<<location->data<<endl;
    }else{
        cout<<" Not found";
    }
}

void printinrange(binarytreenode<int>* root, int min, int max){
    if(root == NULL){
        return;
    }
    
    if(root->data > max){
        printinrange(root->left, min, max);
    }
    if(root->data < min){
        printinrange(root->right, min, max);
    }
    if(root->data >= min && root->data <= max){
        cout<<root->data<<" ";
        printinrange(root->left, min, max);
        printinrange(root->right, min, max);
    }
}

class Answer{       //actully this is less time cosuming
    public:
    int min;
    int max;
    bool itis = false;
};
Answer checkbst(binarytreenode<int>* root){
    Answer ans;
    if(root == NULL){
        ans.itis = true;
        ans.min = INT32_MAX;
        ans.max = INT32_MIN;
        return ans;
    }
    Answer l = checkbst(root->left);
    Answer r = checkbst(root->right);
    
    ans.itis = ((l.max < root->data && r.min >= root->data) && l.itis && r.itis);
    ans.min = min(root->data,min(r.min,l.min));
    ans.max = max(max(r.max, l.max), root->data);
    return ans;

}


bool checkbst2(binarytreenode<int>* root, int min = INT32_MIN, int max = INT32_MAX){   //more time cosuming
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }
    bool check1 = checkbst2(root->left, min, root->data-1);
    bool check2 = checkbst2(root->right, root->data, max);
    return (check1 && check2);
}

binarytreenode<int>* construct(int * arr, int s, int e){//construct with an iorder array
    if(s>e){
        return NULL;
    }
    int mid = (e-s)/2 +s;
    binarytreenode<int>* root = new binarytreenode<int>(arr[mid]);
    root->left = construct(arr, s, mid-1);
    root->right = construct(arr, mid+1, e);
    return root;
}

template<typename N>
class node{
    public:
    N data;
    node * next;
    node(N data){
        this->data = data;
        next = NULL;
    } 
};

pair<node<int>*, node<int>*> bsttoll(binarytreenode<int>* root){
    if(root == NULL){
        pair<node<int>*, node<int>*> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    pair<node<int>*, node<int>*> left = bsttoll(root->left);
    pair<node<int>*, node<int>*> right = bsttoll(root->right);
    pair<node<int>*, node<int>*> ans;
    node<int>* rootnode = new node<int>(root->data);
    if(left.first != NULL){
        ans.first = left.first;
        left.second->next = rootnode;
    }else{
        ans.first = rootnode;
    }
    if(right.first != NULL){
        rootnode->next= right.first;
        ans.second = right.second;
    }else{
        ans.second = rootnode;
    }
    return ans;
}

void printlist(node<int>* head){
    node<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

vector<int>* findpathinbst(binarytreenode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    if(data < root->data){
        vector<int>* leftoutput = findpathinbst(root->left, data);
        if(leftoutput != NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
    }

    if(data >= root->data){
        vector<int>* rightoutput = findpathinbst(root->right, data);
        if(rightoutput != NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }
    }else{
        return NULL;
    }
    
}
int main(){
    binarytreenode<int> * root = takeinputlevelwise();
    //int key;
    //cin>>key;
    //findthekey(root, key);
    //printinrange(root, 6, 10);
    if(checkbst(root).itis){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    
    if(checkbst2(root)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    /*int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    binarytreenode<int>* ans = construct(arr, 0, size-1);
    printlevelwise2(ans);*/

    //node<int>* head = bsttoll(root).first;
    //printlist(head);
    /*int data;
    cin>>data;
    vector<int>* output = findpathinbst(root, data);
    for(int i=0; i<output->size(); i++){
        cout<<output->at(i)<<" ";
    }*/
    return 0;
}
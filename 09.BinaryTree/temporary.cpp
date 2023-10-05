#include "binarytreenode.h"

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

// list of each level
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
vector<node<int>*> levellist(binarytreenode<int>* root){
    vector<node<int>*> v;
    if(root == NULL){
        v.push_back(NULL);
        return v;
    }
    node<int>* head = NULL;
    node<int>* temp = head;
    queue<binarytreenode<int>*> q;
    
    q.push(root);
    q.push(NULL);
    while(q.size() != 0){
        binarytreenode<int>* front = q.front();
        q.pop();
        if(front == NULL){
            temp->next = NULL;
            if(q.size() == 0){
                break;
            }
            q.push(NULL);
            temp = NULL;
            head = NULL;
            
        }else{
            node<int>* newnode = new node<int>(front->data);
           if(head == NULL){
                head = newnode;
                temp = newnode;
                v.push_back(head);
            }else{
                temp->next = newnode;
                temp = newnode;
            }
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            } 
        }

    }
    return v;
}

void printfucntion2(vector<node<int>*> ans){
    if(ans[0] == NULL){
        return;
    }
    for(int i=0; i<ans.size(); i++){
        node<int>* temp = ans[i];
        while(temp != NULL){
            int data = temp->data;
            cout<<data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
}

void change(vector<int> s){
    s.push_back(8);
    s.push_back(5);
    for(int i=0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    //binarytreenode<int>* root = takeinputlevelwise();
    //vector<node<int>*> ans = levellist(root);
    //printfucntion2(ans);
    vector<int> v;
    v.push_back(5);
    v.push_back(0);
    change(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
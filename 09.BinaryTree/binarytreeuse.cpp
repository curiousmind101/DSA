#include "binarytreenode.h"

void printfunction(binarytreenode<int>* root){  //depth first
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<", ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data<<", ";
    }
    cout<<"\n";
    printfunction(root->left);
    printfunction(root->right);
}

binarytreenode<int>* takeinput(){
    cout<<"Enter Data: "<<endl;
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    cout<<"Enter Left of "<<rootdata<<endl;
    root->left = takeinput();
    cout<<"Enter Right of "<<rootdata<<endl;
    root->right = takeinput();
    return root;
}

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

void printlevelwise(binarytreenode<int>* root){
    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        binarytreenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<": ";
        if(front->left != NULL){
            cout<<"L"<<front->left->data<<", ";
            pendingnodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<"R"<<front->right->data<<", ";
            pendingnodes.push(front->right);
        }
        cout<<"\n";
    }
}

int countnode(binarytreenode<int>* root){
    if(root == NULL){
        return 0;
    }
    return (countnode(root->left) + countnode(root->right) + 1);
}

bool isNodepresent(binarytreenode<int>* root, int k){
    if(root == NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }
    bool flag = false;
    flag = isNodepresent(root->left, k);
    if(flag == true){
        return true;
    }
    flag = isNodepresent(root->right, k);
    return flag;
}

int heightoftree(binarytreenode<int>* root){
    if(root == NULL){
        return 0;
    }
    return (max(heightoftree(root->left), heightoftree(root->right))+1);
}

void printatlevelk(binarytreenode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<", ";
    }
    printatlevelk(root->left, k-1);
    printatlevelk(root->right, k-1);
    return;
}

void mirrorbinarytree(binarytreenode<int>* root){
    if((root->left == NULL) && (root->right == NULL)){
        return;
    }
    binarytreenode<int>* swap = root->right;
    root->right = root->left;
    root->left = swap;
    mirrorbinarytree(root->left);
    mirrorbinarytree(root->right);
    return;
}

void print_inorder(binarytreenode<int>* root){
    if(root == NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<", ";
    print_inorder(root->right);
    return;
}


//pre-order
void print_preorder(binarytreenode<int>* root){  //depth first
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
    return;
}

void print_postorder(binarytreenode<int>* root){
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}


/******* Make binarytree with pre and inorder array or list ********************************************/
binarytreenode<int>* buildtree(int *pre, int *in, int preS, int preE, int inS, int inE){
    if(inS > inE){
        return NULL;
    }

    int rootData = pre[preS];
    binarytreenode<int>* root = new binarytreenode<int>(rootData);
    int rootinedex = -1;
    for(int i=inS; i<=inE; i++){
        if(in[i] == rootData){
            rootinedex = i;
            break;
        }
    }
    int lpreS = preS+1;
    int linS = inS;
    int linE = rootinedex-1;
    int lpreE = linE - linS + lpreS;
   
    int rpreS = linE - linS + lpreS+1;
    int rpreE = preE;
    int rinS = rootinedex+1;
    int rinE = inE;
    root->left = buildtree(pre, in, lpreS, lpreE, linS, linE);
    root->right = buildtree(pre, in , rpreS, rpreE, rinS, rinE);
    return root;
}

binarytreenode<int>* makewith_pre_in(int *pre, int *in, int size){
    return buildtree(pre, in, 0, size-1, 0, size-1);
    
}
/*****************************************************************************************************/

/******* Make binarytree with post and inorder array or list ********************************************/

binarytreenode<int>* buildtreepost(int *post, int *in, int postS, int postE, int inS, int inE){
    if(inS > inE){
        return NULL;
    }

    int rootData = post[postE];
    binarytreenode<int>* root = new binarytreenode<int>(rootData);
    int rootinedex = -1;
    for(int i=inS; i<=inE; i++){
        if(in[i] == rootData){
            rootinedex = i;
            break;
        }
    }
    int lpostS = postS;
    int linS = inS;
    int linE = rootinedex-1;
    int lpostE = linE - linS + lpostS;
   
    int rpostS = linE - linS + lpostS+1;
    int rpostE = postE-1;
    int rinS = rootinedex+1;
    int rinE = inE;
    root->left = buildtreepost(post, in, lpostS, lpostE, linS, linE);
    root->right = buildtreepost(post, in , rpostS, rpostE, rinS, rinE);
    return root;
}

binarytreenode<int>* makewith_post_in(int *pre, int *in, int size){
    return buildtreepost(pre, in, 0, size-1, 0, size-1);
    
}
/***********************************************************************************************************/

/***********************************************************************************************************/
// Diameter of binarytree

int diameter(binarytreenode<int>* root){    // AAM zindagi 
    if(root == NULL){
        return 0;
    }
    int option1 = heightoftree(root->left) +  heightoftree(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
}
/***********************************************************************************************************/

pair<int, int> diameterheight(binarytreenode<int>* root){    // Metnos Zindagi
    if(root == NULL){                  //But aditya verma has bda mentos zindagi
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = diameterheight(root->left);
    pair<int, int > rightans = diameterheight(root->right);
    int ld = leftans.first;
    int lh = leftans.second;
    int rd = rightans.first;
    int rh = rightans.second;

    int height = max(lh, rh)+1;
    int diameter = max(lh+rh, max(ld, rd));
    pair<int, int> ans;
    ans.first = diameter;
    ans.second = height;
    return ans;
}

pair<int, int> min_max(binarytreenode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = INT32_MAX;
        p.second = INT32_MIN;
        return p;
    }

    pair<int, int> leftans = min_max(root->left);
    pair<int, int> rightans = min_max(root->right);
    int lmin = leftans.first;
    int lmax = leftans.second;
    int rmin = rightans.first;
    int rmax = rightans.second;

    pair<int, int> ans;

    ans.first = min(min(lmin, rmin), root->data);
    ans.second = max(max(lmax, rmax), root->data);

    return ans;
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

// remove leaf nodes 

void removeleafnodes(binarytreenode<int>* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->left->left == NULL && root->left->right == NULL){
        delete root->left;
        root->left = NULL;
    }
    if(root->right->left == NULL && root->right->right == NULL){
        delete root->right;
        root->right = NULL;
    }
    removeleafnodes(root->left);
    removeleafnodes(root->right);
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

void printfucntion2(vector<node<int>*> v){
    if(v[0] == NULL){
        return;
    }
    for(int i=0; i<v.size(); i++){
        node<int>* temp = v[i];
        while(temp != NULL){
            int data = temp->data;
            cout<<data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
}


vector<node<int>*> levellist(binarytreenode<int>* root){
    vector<node<int>*> v;
    if(root == NULL){
        v.push_back(NULL);
        return v;
    }
    node<int>* head = NULL;
    queue<binarytreenode<int>*> q;
    node<int>* temp = head;
    q.push(root);
    q.push(NULL);
    while(q.size() != 0){
        binarytreenode<int>* front = q.front();
        q.pop();
        if(front != NULL){
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
        }else{
            temp->next = NULL;
            if(q.size() == 0){
                break;
            }
            q.push(NULL);
            temp = NULL;
            head = NULL;
        }

    }
    return v;
}

void zigzag(binarytreenode<int>* root){
    if(root == NULL){
        return;
    }
    queue<binarytreenode<int>*> q;
    stack<binarytreenode<int>*> s;
    q.push(root);
    q.push(NULL);
    int k = 1;
    while(q.size() != 0){
        binarytreenode<int>* front = q.front();
        q.pop();
        if(front != NULL){
            if(k%2 != 0){
                cout<<front->data<<" ";
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
            else{
                s.push(front);
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }                
        }else{
            while(s.size() != 0){
                binarytreenode<int>* top = s.top();
                cout<<top->data<<" ";
                s.pop();
            }
            if(q.size() == 0){
                break;
            }
            cout<<"\n";
            q.push(NULL);
            k++;
        }
    }
    return;
}

void nodeswithoutsiblings(binarytreenode<int>* root){
    if(root == NULL){
        return;
    }
    if((root->left == NULL) && (root->right == NULL)){
       return;
    }
    if((root->left != NULL) && (root->right == NULL)){
        cout<<root->left->data<<endl;
    }
    if((root->left == NULL) && (root->right != NULL)){
        cout<<root->right->data<<endl;
    }
    nodeswithoutsiblings(root->left);
    nodeswithoutsiblings(root->right);
}

int main(){
    binarytreenode<int>* root = takeinputlevelwise();
    char seperate[] = "**********************************************************************\n";
    //zigzag(root);
    nodeswithoutsiblings(root);
    //vector<node<int>*> v = levellist(root);
    //printfucntion2(v);
    return 0;
}

/*
int main(){
    /*binarytreenode<int>* root = new binarytreenode<int>(1);
    binarytreenode<int>* node1 = new binarytreenode<int>(2);
    binarytreenode<int>* node2 = new binarytreenode<int>(3);
    root->left = node1;
    root->right = node2;
    printfunction(root);*/
    //binarytreenode<int>* root = takeinputlevelwise();
    //char seperate[] = "**********************************************************************\n";
    //cout<<seperate;

    //printlevelwise(root);
    //cout<<seperate;

    //mirrorbinarytree(root);
    //printlevelwise(root);
    //cout<<seperate;

    /*int h = heightoftree(root);
    cout<<h<<"\n"<<seperate;

    cout<<countnode(root)<<"\n"<<seperate;

    int n;
    cin>>n;
    bool ans = isNodepresent(root, n);
    if(ans == true){
        cout<<"Present"<<"\n"<<seperate;
    }else{
        cout<<"Absent"<<"\n"<<seperate;
    }

    int k;
    cin>>k;
    printatlevelk(root, k);*/

    /*print_inorder(root);
    cout<<"\n"<<seperate<<"\n";

    print_preorder(root);
    cout<<"\n"<<seperate<<"\n";

    print_postorder(root);
    cout<<"\n"<<seperate<<"\n";

    //int post[] = {25, 50, 30, 10, 40, 45, 20, 5};
    //int in[] = {25, 10, 30, 50, 5, 40, 20, 45};
    //binarytreenode<int>* root = makewith_post_in(post, in, 8);
    //print_preorder(root);
    //cout<<diameter(root)<<endl;
    //pair<int, int> ans = diameterheight(root);

    //pair<int, int> minmax = min_max(root);
    //cout<<minmax.first<<endl;
    //cout<<minmax.second<<endl;
    //cout<<ans.first<<endl;
    //removeleafnodes(root);
    //printlevelwise2(root);
    vector<node<int>*> v = levellist(root);
    return 0;
}*/

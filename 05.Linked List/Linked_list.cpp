#include<bits/stdc++.h>
using namespace std;

//Node Class
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

class Pair{
    public:
    Node* head;
    Node* tail;
};

//taking input a list
Node* takeinput(){
    int data;
    cin>>data;
    Node *head = NULL;
    //Thought 
    Node *temp;
    while(data != -1){
        Node *newnode = new Node(data);
        //Thought
        if(head == NULL){               
            head = newnode;
            temp = newnode; //or head;
        }
        else{
            temp -> next = newnode;       //basically maintaining temp as a tail of the list
            temp = newnode;
        }
        cin>>data;

        /*
        Node *temp = head;
        if(head == NULL){
            head = newnode;
        }else{
            while(temp -> next != NULL){    //Not an optimal solution
                temp = temp->next;
            }
            temp -> next = newnode;
        }
        cin>>data;
        */
    }
    return head;
}

// print the function
void printfun(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Insertion with the help of loop
Node* Insertnode(Node *head, int i, int data){
    Node * temp = head;
    Node * newnode = new Node(data);
    int count = 0;

    if(i == 0){
        newnode -> next = head;
        head = newnode;
        return head;
    }

    while(temp != NULL && count < i-1 ){
        temp = temp -> next;
        count++;
    }

    //method-1
    //newnode->next = temp->next;
    //temp->next = newnode;

    //method-2
    if(temp != NULL)
    {
    Node *a = temp -> next;
    temp->next = newnode;
    newnode->next = a;
    }
    return head;
}

//deletion with the help of loop
Node* deletenode(Node *head, int i){
    Node * temp = head;
    int count = 0;
    while(count < i-1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(i==0){
        head = temp->next;
        delete temp;
        return head;
    }

    if(temp != NULL){
    Node *a = temp->next;
    temp-> next = a-> next;
    delete a;
    }
    return head;
}

// try with i-1; succesfull : insertion of new node in list
Node * insertion(Node * head, int i, int data){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;
    }
    head->next = insertion(head->next, i-1,  data);
    return head;
}

// deletion of a Node in list
Node * deletion(Node * head, int i){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    head->next = deletion(head->next, i-1);
    return head;
}

//data at ith index
int at(Node* head, int i){
    if(head == NULL){
        return -1;
    }
    if(i == 0){
        return head->data;
    }
    return at(head->next, i-1);
}

//function for length of the list
int listLength(Node * head){
    Node * tail = head;
    if(tail->next == NULL){
        return 1;
    }
    else{
        return listLength(tail->next)+1;
    }
}

// Median of a linked list
int median(Node *slow, Node*fast){          //pass (head , head->next)
    if((fast == NULL)){
        return slow->data;
    }
    if(fast->next == NULL){
        return slow->data;
    }
    return median(slow->next, fast->next->next);
}

Node * median2(Node * slow, Node * fast){    //pass (head, head->next)
    if((fast == NULL)){
        return slow;
    }
    if(fast->next == NULL){
        return slow;
    }
    return median2(slow->next, fast->next->next);
}

//merge two sorted list
Node * mergelist(Node *h1, Node *h2){
    if(h1 == NULL){
        cout<<"only c2 is there";
        return h2;
    }
    if(h2 == NULL){
        cout<<"only c1 is there";
        return h1;
    }
    Node * fh = NULL;
    Node * ft = NULL;
    Node * c1 = h1;
    Node * c2 = h2;
    if(c1->data < c2->data){
        fh = c1;
        ft = c1;
        c1 = c1->next;
    }
    else{
        fh = c2;
        ft = c2;
        c2 = c2->next;
    }
    while(c1 != NULL && c2 != NULL){
        if(c1->data < c2->data){
            ft->next = c1;
            ft = c1;
            c1 = c1->next;
        }
        else{
            ft->next = c2;
            ft = c2;
            c2 = c2->next;
        }
    }
    if(c1 == NULL){
        ft->next = c2;

    }else{
        ft->next = c1;
    }
    return fh;
}


//mergesort for linkedlist
Node * mergesort(Node *head){
    if(head->next == NULL){
        return head;
    }
    Node * med = median2(head, head->next);
    Node * h1 = head;
    Node * h2 = med->next;
    med->next = NULL;
    h1 = mergesort(h1);
    h2 = mergesort(h2);
    return mergelist(h1, h2);
}

Node* reverselist(Node * head){  // time complexity n^2
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node * reversed = reverselist(head->next);
    Node * temp = reversed;
    while(temp->next != NULL){
        temp=temp->next;
    }

    temp->next = head;
    head->next = NULL;
    return reversed;
    
}

//executer for double pointer reverse function.
Pair reverselistXT(Node * head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair reversed = reverselistXT(head->next);
    reversed.tail->next = head;
    head->next= NULL;
    Pair ans;
    ans.head = reversed.head;
    ans.tail = head;
    return ans;
}

Node * reverseLL(Node *head){
    Pair recieve = reverselistXT(head);
    return recieve.head;
}

Node * reverseLLXT(Node * head){              //simplest way
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node * reversed = reverseLLXT(head->next);
    Node * tail = head->next;
    tail->next = head;
    head->next = NULL;
    return reversed;
}

Node * reverselIT(Node * head){
    Node * temp = NULL;
    Node * n = head->next;
    while(n != NULL){
        head->next = temp;
        temp = head;
        head = n;
        n = n->next;
    }
    head->next = temp;
    return head;
}

/*
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node* insertionSort(Node* head){     
    Node* i = head->next;
    while(i != NULL){
        int temp = i->data;
        Node* j = i->prev;
        while(temp < j->data && j != NULL){
            j->next->data = j->data;
            j = j->prev;
        }
        
        if(j != NULL){
            j->next->data = temp;
        }else{
            head->data = temp;
        }
        
        i = i->next;
    }
    return head;
}

Node* kSorteddll(Node* head, int k){
    Node* i = head->next;
    while(i != NULL){
        int temp = i->data;
        Node* j = i->prev;
        int p = 1;
        while(temp < j->data && j != NULL && p<=k){
            j->next->data = j->data;
            j = j->prev;
            p++;
        }
        
        if(j != NULL){
            j->next->data = temp;
        }else{
            head->data = temp;
        }
        
        i = i->next;
    }
    return head;
}

Node* lastinfront(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    Node* nexthead = temp->next;
    nexthead->next = head;
    temp->next = NULL;
    return nexthead;
}
Node* takeinputrec(){   //recursive method O(n)
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* newnode = new Node(data);
    newnode->next = takeinputrec();
    return newnode;
}

Node* takeinputdll(){   //recursive method O(n)
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* newnode = new Node(data);
    newnode->next = takeinputdll();
    if(newnode->next != NULL){
        newnode->next->prev = newnode;
    }
    return newnode;
}

Node* takeinput(){
    int data;
    cin>>data;
    
    Node* head = NULL;
    Node* tail;
    while(data != -1){  
        //head tail method O(n)
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
        
    }
    return head;
}

void insertNode(Node* head, int i, int data){    //at ith position with //iterative
    //so, to insert a new element at ith postion i need to now the i-1 postion
    Node* newnode = new Node(data);
    if(i == 1){
        newnode->next = head;
        return;
    }
    
    Node* temp = head;
    int count = 1;
    while(temp->next != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return;
}

Node* insertNoderec(Node* head, int i, int data){
    if(i==1 || head == NULL){
        Node* newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        return head;   //new head
    }
    head->next = insertNoderec(head->next, i-1, data);
    return head;
}

Node* deleteithpos(Node* head, int i){
    if(head == NULL){
        return NULL;
    }//if i is greater than the length of the list
    if(i==1){
        Node* newhead = head->next;
        head->next = NULL;
        delete head;
        return newhead;
    }
    head->next = deleteithpos(head->next, i-1);
    return head;
}

void printList(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}

void printdll(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cout<<temp->data<<" ";
        prev = temp;
        temp=temp->next;
    }
    cout<<endl;
    while(prev != NULL){
        cout<<prev->data<<" ";
        prev = prev->prev;
    }
    cout<<endl;
    return;
}

//rotate by k nodes for singly

Node* rotatebyknodes(Node* head, int k){
    Node* temp = head;
    Node* newhead = NULL;
    int p=1;
    while(p < k){
        temp = temp->next;
        p++;
    }
    newhead = temp->next;
    temp->next = NULL;
    temp=newhead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = head;
    
    return newhead;
}

//for doubly linked list

Node* rotatebyknodesdll(Node* head, int k){
    Node* temp = head;
    Node* newhead = NULL;
    int p=1;
    while(p <= k && temp->next != NULL){
        temp = temp->next;
        p++;
    }
    newhead = temp;
    temp->prev->next = NULL;
    temp->prev = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
    return newhead;
}

Node* reversebyGrpofN(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    
    Node* nextnode = head->next;
    Node* curr = head;
    int cnt  = 0
    while(cnt < k && curr != NULL){
        curr->next = curr->prev;
        curr->prev = nextnode;
        curr = nextnode;
        nextnode = nextnode->next;
        cnt++;
    }
    curr->next = curr->prev;
    head->next = reversebyGrpofN(nextnode, k);
    if(head->next != NULL){
        head->next->prev = head;
    }
    return curr;
}

int main(){
    //Node* head = takeinputrec();
    //printList(head);
    //cout<<endl;
    //int i, data;
    // cin>>i>>data;
    // insertNoderec(head, i, data);
    // deleteithpos(head);
    //head = lastinfront(head);
    Node* head = takeinputdll();
    printdll(head);
    //head = insertionSort(head);
    //head = kSorteddll(head, 2);
    head = rotatebyknodesdll(head, 5);
    printdll(head);
    return 0;
}
*/


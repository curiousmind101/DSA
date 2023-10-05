#include<bits/stdc++.h>
#include "Linked_list.cpp"
using namespace std;

vector<int> stock_span(Node* head){  // O(n)
    Node* temp = head->next;
    int prev = head->data;
    stack<int> s;
    vector<int> v;
    s.push(0);
    v.push_back(1);
    int index = 1;
    while(temp != NULL){
        if(temp->data > prev){
            while(at(head, (s.top()))<(temp->data)){
                s.pop();
            }
            v.push_back(index-s.top());
            s.push(index);
        }else{
            s.push(index);
            v.push_back(1);
        }
        index++;
        prev = temp->data;
        temp = temp->next;
    }
    return v;
}


//worst case
/*queue<int> Stock_span(Node* head){
    queue<int> s;
    int count=1;
    Node* temp1 = head;
    while(temp1 != NULL){
        Node * temp2 = head;
        while(temp2 != temp1){
            if((temp2->data)<=(temp1->data)){
                count++;
            }else{
                count=1;
            }
            temp2 = temp2->next;
        }
        s.push(count);
        count=1;
        temp1 = temp1->next;
    }
    return s;
}*/

int main(){
    Node * head = takeinput();
    //queue<int> s = Stock_span(head);
    vector<int> v = stock_span(head);
    for(auto& it:v){
        cout<<it<<" ";
    }
    /*while(!(s.empty())){
        cout<<s.front()<<" ";
        s.pop();
    }*/
    cout<<"\n";
    return 0;
}
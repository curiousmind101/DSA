#include "Linked_list.cpp"
using namespace std;

Node * bubblesort(Node  *head){
    int L = listLength(head);
    Node *temp = head;
    Node *prev = head;
    for(int i=0; i<(L-1); i++){
        while(temp->next != NULL){
            if(temp->data > (temp->next)->data){
                if(prev == temp){
                    prev->next = (temp->next)->next;
                    prev=temp->next;
                    prev->next=temp;
                    head = prev;
                }
                else{
                    prev->next=temp->next;
                    temp->next=temp->next->next;
                    prev->next->next = temp;
                    prev=prev->next;
                }
            }else{
                temp = temp->next;
                prev = prev->next;
            }
            
        }
    }
    return head;
}

/*Node * bubblesort(Node  *head){
    int L = listLength(head);
    Node *temp = head;
    for(int i=0; i<(L-1); i++){
        for(int j=0; j<(L-i-1); j++){
            if(temp->data > (temp->next)->data){
                int swap = temp->data;
                temp->data = (temp->next)->data;
                (temp->next)->data = swap;
            }
            temp = (temp->next);
        }
        temp = head;
    }
    return head;
}*/

int main(){
    Node * head = takeinput();
    head = bubblesort(head);
    printfun(head);
}
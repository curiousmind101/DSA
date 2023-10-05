#include "Linked_list.cpp"

int main(){
    Node * head = takeinput();
    printfun(head);

    /*Node * med = median2(head, head->next);
    int me = med->data;
    cout<<me<<endl;*/
    head = (mergesort(head));
    printfun(head);
    return 0;
}
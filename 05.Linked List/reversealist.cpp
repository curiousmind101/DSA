#include "Linked_list.cpp"

int main(){
    Node * head = takeinput();
    printfun(head);

    head = reverselIT(head);
    printfun(head);
    return 0;
}
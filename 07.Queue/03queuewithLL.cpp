#include<iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queuewithLL{
    public:
    Node<T> *first = NULL;
    Node<T> *last = NULL;
    int size;
    
    queuewithLL(){
        size = 0;
    }
    void setfirst(Node<T> * f){
        this->first = f;
    }
    void add(T data){
        Node<T> *newdata = new Node<T>(data);
        if(first == NULL){
            first = newdata;
            last = newdata;
            size++;
        }else{
            last->next = newdata;
            last = newdata;
            size++;
        }
    }

    void pop_front(){
        Node<T> *temp = first;
        first = first->next;
        delete temp;
        size--;
    }

    T sfirst(){
        T ans = first->data;
        return ans;
    }

    bool isempty(){
        if(first == NULL){
            return true;
        }else{
            return false;
        }
    }

    int sizeq(){
        return size;
    }

    void emplace(T data){
        last->data = data;
    }
    Node<T> * reversequeue(Node<T> * first1){
    if(first1 == NULL || first1->next == NULL){
        return first1;
    }
    Node<T> * reversed = reversequeue(first1->next);
    Node<T> * last1 = first->next;
    last1->next = first1;
    first1->next = NULL;
    return reversed;
}
};


int main(){
    queuewithLL<int> ql;
    if(ql.isempty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"Not empty"<<endl;
    }
    ql.add(5);
    ql.add(10);
    ql.add(20);
    cout<<ql.sfirst()<<endl;
    queuewithLL<int> ql2;
    Node<int> * f2 = ql.reversequeue((ql.first));
    ql2.setfirst(f2);
    cout<<ql2.sfirst()<<endl;
    /*ql.pop_front();
    cout<<ql.sfirst()<<endl;
    ql.emplace(15);
    ql.pop_front();
    cout<<ql.sfirst()<<endl;
    if(ql.isempty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"Not empty"<<endl;
    }*/

    return 0;
}
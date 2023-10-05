#include<bits/stdc++.h>
using namespace std;


class Trienode{
    public:
    char data;
    Trienode **children = new Trienode*[26];
    bool isTerminal;
    Trienode(char data){
        this->data = data;
        isTerminal = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
    ~Trienode(){
        for(int i=0; i<26; i++){
            delete children[i];
        }
        delete [] children;
    }

};
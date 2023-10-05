#include "Trienode.h"

class Tries{
    public:
    Trienode *root;
    Tries(){
        root = new Trienode('\0');
    }
    public:
    void insertword(Trienode* root, string word){     // Dictionary
        //Base Case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        //Small Calculation
        int index = word[0]-'a';
        Trienode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        //Recursive Call
        insertword(child, word.substr(1));
        return;
    }
    void insertword(string s){
        insertword(root, s);
    }

    //Search Set
    bool search(Trienode* root, string word){     //Dictionary
        //base case
        if(word.size() == 0){
            return root->isTerminal;
        }

        //small calc + recursive call
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            Trienode* child = root->children[index];
            return search(child, word.substr(1));
        }
        return false;
    }
    bool search(string word){
        return search(root, word);
    }

    bool searchpattern(Trienode *root, string s){   //To Search a pattern
        //base case
        if(s.size() == 0){                         
            return true;                            //Only difference from upper one
        }

        //small calc + recursive call
        int index = s[0]-'a';
        if(root->children[index] != NULL){
            Trienode* child = root->children[index];
            return searchpattern(child, s.substr(1));
        }
        return false;
    }
    bool searchpattern(string word){
        return searchpattern(root, word);
    }


    void insertforpattern(string word){                  //To Insert a pattern
        int size = word.size();
        while(size>0){
            insertword(root, word.substr(--size));
        }
        return;
    }


    //Remove Set
    void removeword(Trienode* root, string word){
        //base case
        if(word.size() == 0){
            root->isTerminal = false;
            return;  
        }

        Trienode* child;
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return;
        }
        removeword(child, word.substr(1));
        if(child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
        return;
    }
    void removeword(string word){
        removeword(root, word);
    }
};
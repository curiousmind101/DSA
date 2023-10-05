#include "Tries.cpp"

vector<string> searchwords(Trienode* root, vector<string>& v, string s){
    if(root->data != '\0'){
        s += root->data;
    }
    if(root->isTerminal){
        v.push_back(s);
    }
    for(int i=0; i<26; i++){
        if(root->children[i] != NULL){
            searchwords(root->children[i], v, s);
        }
    }
    return v;
}

bool searchpelindrome(Tries t){
    vector<string> v;
    string s;
    v = searchwords(t.root, v, s);
    bool ans = false;
    for(auto x:v){
        int s = 0, e = x.size()-1;
        while(s<e){
            if(x[s++] != x[e--]){
                break;
            }
        }
        if(s>e){
            return true;
        }
    }

    for(auto x:v){
        int s = 0, e = x.size()-1;
        while(s<e){
            swap(x[s++], x[e--]);
        }
        if(t.search(x)){
            return true;
        }
    }
    return false;
}


void printhelp(Trienode* root, string s){
    if(root->isTerminal==true){
        cout<<s<<"\n";
    }
    for(int i=0; i<26; i++){
        if(root->children[i] != NULL){
            printhelp(root->children[i], s+root->children[i]->data);
        }
    }
    return;
}

void autocomplete(Trienode* root, string word, string output){
    if(word.size() == 0){
        printhelp(root, output);
        return;
    }
    if(root->children[word[0]-'a'] != NULL){
        autocomplete(root->children[word[0]-'a'], word.substr(1), output);
    }
    return;
}
int main(){
    Tries t;
    /*string s ="barcode";
    t.insertforpattern(s);
    int size = s.size();
    if(t.searchpattern("nba")){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }*/

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        t.insertword(s);
    }
    string s;
    cin>>s;
    autocomplete(t.root, s, s);
}
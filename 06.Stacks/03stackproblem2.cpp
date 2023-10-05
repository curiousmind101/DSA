#include<bits/stdc++.h>
using namespace std;

bool checkredundant(string s){
    stack<char> st;
    int l = s.length();
    int count =0;
    for(int i=0; i<l; i++){
        if(s[i] != ')'){
            st.push(s[i]);
        }
        else{
            while(st.top() != '('){ 
                st.pop();
                count++;
            }
            if(count==0){
                st.pop();
                return true;
                break;
            }else{
                st.pop();
                count=0;
            }
        }     
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    if(checkredundant(s)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}
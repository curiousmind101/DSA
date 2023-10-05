#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int n = str.length();

    stack<char> s;
    //valid Paranthesis
    for(int j=0; j<n; j++){
        if(str[j] == '('){
            s.push(')');
        }
        if(str[j] == '{'){
             s.push('}');
        }
        if(str[j] == '['){
             s.push(']');
        }
    }

    for(int k=0; k<n; k++){
        if((str[k] == ')') || (str[k] == '}') || (str[k] == ']')){
            if(str[k] != s.top()){
                cout<<"false\n";
                return 0;
            }else{
                s.pop();
            }
        }
    }
    if(s.empty()){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }
    return 0;
}
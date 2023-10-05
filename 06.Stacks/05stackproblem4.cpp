#include<bits/stdc++.h>
using namespace std;

int possiblereversal(string s){
    stack<char> s;
    int i=0;
    while(s[i]!='\0'){
        if
        i++;
    }
}

int Balancebracket(string s){
    int o = 0; 
    int c = 0;
    int i=0;
    while(s[i] != '\0'){
        if(s[i] == '{'){
            o++;
        }else{
            c++;
        }
        i++;
    }
    if((o+c)%2 != 0){
        return -1;
    }else{
        if(o>c){
            return (((o+c)/2)-c);
        }
        else{
            return (((o+c)/2)-o);
        }
    }
}

int main(){
    string s;
    cin>>s;
    cout<<Balancebracket(s)<<endl;
    return 0;
}
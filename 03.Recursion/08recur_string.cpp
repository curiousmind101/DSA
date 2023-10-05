#include<bits/stdc++.h>
using namespace std;


int length(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    else{
        return (length(s+1)+1);
    }
}

void remove(char s[], char rem){
    if(s[0]=='\0'){
        return;
    }
    if(s[0] == rem){     // Working with (s[0] != 'x')  not with (s[0] != rem)
         int i=1;
        while(s[i] != '\0'){
            s[i-1] = s[i];
            i++;
        }
        s[i-1] = s[i];
        remove(s);
    }else{
        remove(s+1);
    }
} 

int main(){
    char s[100];
    cin>>s;
    cout<<length(s)<<endl;
    char rem='k';
    remove(s, rem);
    cout<<s<<" ";
    cout<<length(s)<<" ";
    return 0;
}
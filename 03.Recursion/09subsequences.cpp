#include<iostream>
#include<math.h>
using namespace std;


int subs(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    string smallstr = input.substr(1);
    int smallosize= subs(smallstr, output);
    for(int i=0; i<smallosize; i++){
        output[smallosize + i] = input[0]+output[i];
    }
    return 2*smallosize;
}

int main(){
    string s;
    cin>>s;
    int x = s.size();
    int sout = pow(2, x);
    string *output = new string[sout];
    subs(s, output);
    for(int i=0; i<sout; i++){
        cout<<output[i]<<"\n";
    }
    return 0;
}
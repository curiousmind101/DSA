#include<iostream>
#include<vector>
using namespace std;

//User function template for C++


vector<int> factorial(int N){
        // code here
    vector<int> ans;
    long long fact = 1;
    for(int i=2; i<=N; i++){
        fact*=i;
    }
        
    int n=0;
    while(fact>0){
        ans.push_back(fact%10);
        fact/=10;
        n++;
    }
    
    int s=0;
    int e=n-1;
    while(s<e){
        int temp = ans[s];
        ans[s] = ans[e];
        ans[e] = temp;
        s++;
        e--;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> ans = factorial(n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int lastocr(int v[], int size, int key){
    if(size == 0){
        return -1;
    }
    int ans = lastocr(v+1, (size-1), key);
    if(ans == -1){
        if( v[0] == key){
            return 0;
        }else{
            return -1;
        }
    }else{
        return (ans+1);
    }
}

int lastOcr(int v[], int size, int key){
    int ans = -1;
    for(int i=0; i<size; i++){
        if(v[i] == key){
            ans = i;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int key;
    cin>>key;
    cout<<lastocr(v, n, key);
    return 0;
}
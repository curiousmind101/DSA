#include<bits/stdc++.h>
using namespace std;

void heapsort(vector<int>& v){
    if(v.size() == 0 || v.size() == 1){
        return;
    }
    int c = 1;  //current index/ child index / newly inserted
    while(c < v.size()){
        int ci = c;
        while(ci > 0){
            int pi = (ci-1)/2;
            if(v[ci] < v[pi]){
                swap(v[ci], v[pi]);
            }else{
                break;
            }
            ci = pi;
        }
        c++;
    }

    int last = v.size()-1;
    while(last !=  0){
        swap(v[0], v[last]);
        int pi = 0;
        int lci = 2*pi+1;
        int rci = 2*pi+2;
        last--;
        while(lci <= last){
            int mini = pi;
            if(v[lci] < v[mini]){
                mini = lci;
            }
            if(v[rci] < v[mini] && rci <= last){
                mini = rci;
            }
            if(mini == pi){
                break;
            }
            swap(v[pi], v[mini]);
            pi = mini;
            lci = 2*pi+1;
            rci = 2*pi+2;
        }
        
    }
    return;
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    heapsort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
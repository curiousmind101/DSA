#include<bits/stdc++.h>
using namespace std;

class PriorityQ{
    vector<int> pq;
    public:
    PriorityQ(){
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(pq.size() == 0){
            return INT32_MIN;
        }
        return pq[0];
    }

    /*void inserthelp(int i){     //better than iterative :by Me
        if(i == 0){               //reached at root
            return;
        }
        int x = (i-1)/2;
        if(pq[x] > pq[i]){
            swap(pq[x], pq[i]);
            inserthelp(x);
        }
        return;
    }*/
    void insertMin(int n){
        pq.push_back(n);
        //inserthelp(pq.size()-1);  //Method-1  better
        //Method-2
        int childindex = pq.size()-1;
        while(childindex > 0){
            int parentindex = (childindex-1)/2;
            if(pq[parentindex] > pq[childindex]){
                swap(pq[parentindex], pq[childindex]);
            }else{
                break;
            }
            childindex = parentindex;
        }
    }

    int removeMin(){
        if(pq.size() == 0){
            return INT32_MIN;  //No element
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int pi = 0;   //parent index
        int lci = 2*pi+1;   // left child index
        int rci = 2*pi+2;   // right child index
        while(lci < pq.size()){
            int minindex = pi;     // to mantain min
            if(pq[lci] < pq[minindex]){
                minindex = lci;
            }
            if(rci < pq.size() && pq[rci] < pq[minindex]){
                minindex = rci;
            }
            if(minindex == pi){
                break;
            }
            swap(pq[minindex], pq[pi]);
            pi = minindex;
            lci = 2*pi+1;   // left child index
            rci = 2*pi+2;   // right child index
        }
        return ans;
    }
    void printpq(){
        for(int i=0; i<pq.size(); i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};


class mxPriorityQ{
    vector<int> pq;
    public:
    mxPriorityQ(){
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
        if(pq.size() == 0){
            return INT32_MIN;
        }
        return pq[0];
    }
    
    void insertMax(int n){
        pq.push_back(n);
        int ci = pq.size()-1;     //current/child index
        while(ci > 0){
            int pi = (ci-1)/2;    //parent index
            if(pq[pi] < pq[ci]){
                swap(pq[pi], pq[ci]);
            }else{
                break;
            }
            ci = pi;
        }
    }

    int removeMax(){
        if(pq.size() == 0){
            return INT32_MIN;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int pi = 0;
        int lci = 2*pi+1;
        int rci = 2*pi+2;

        while(lci < pq.size()){
            int maxindex = pi;
            if(pq[lci] > pq[maxindex]){
                maxindex = lci;
            }
            if(pq[rci] > pq[maxindex] && rci < pq.size()){
                maxindex = rci;
            }
            if( maxindex == pi){
                break;
            }
            swap(pq[maxindex], pq[pi]);
            pi = maxindex;
            lci = 2*pi+1;
            rci = 2*pi+2;
        }
        return ans;

    }
    
    void printpq(){
        for(int i=0; i<pq.size(); i++){
            cout<<pq[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    mxPriorityQ prq;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        //prq.insertMin(m);
        prq.insertMax(m);
    }
    
    prq.printpq();
    while (!prq.isEmpty())
    {
        //cout<<prq.removeMin()<<" ";
        cout<<prq.removeMax()<<" ";
    }
}
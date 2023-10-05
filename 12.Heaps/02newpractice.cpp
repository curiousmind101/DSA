#include<iostream>
#include<vector>
using namespace std;

//min heap
class priorityQueue{
    vector<int> pq;
    public:

    bool isempty(){
        return pq.empty();
    }

    int getSize(){
        return pq.size();
    }

    int top(){
        if(pq.empty()) return INT32_MAX;
        return pq[0];
    }

    void insert(int n){
        pq.push_back(n);

        int ci = pq.size()-1;  //child index

        while(ci > 0){
            int pi = (ci-1)/2;

            if(pq[ci] < pq[pi]){
                swap(pq[ci], pq[pi]);
            }else{
                break;
            }
            ci = pi;
        }
    }

    int pop(){
        if(pq.size()==0) return INT32_MAX;
        int ans = pq[0];

        pq[0] = pq[pq.size()-1];  //or pq.back();
        pq.pop_back();

        int pi = 0;  //parent index

        while(pi < pq.size()){
            int lci = 2*pi+1;
            int rci = 2*pi+2;
            int minindex = pi;
            if(lci < pq.size() && pq[lci] < pq[minindex]){
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
        }

        return ans;
    }

};
int main(){
    priorityQueue pqueue;

    int lb = 1; int ub = 100;
    for(int i=0; i<10; i++){
        int r = (rand()%(ub-lb+1)) + lb;
        pqueue.insert(r);
    }

    for(int i=0; i<10; i++){
        cout<<pqueue.top()<<endl;
        pqueue.pop();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// K-Sorted Array
void ksortedarray(vector<int>& v, int k){    // Method -1 by Me
    priority_queue<int> q;
    for(int i=0; i<k; i++){
        q.push(v[i]);
    }
    int i = 0;
    while(i != v.size()){
        v[i] = q.top();
        q.pop();
        if(i+k != v.size()){
            q.push(v[i+k]);
        }
        i++;
    }
    return;
}

void ksortedarr(vector<int>& v, int k){    // Method -2 by Ninja
    priority_queue<int> q;
    for(int i=0; i<k; i++){
        q.push(v[i]);
    }
    int j = 0;
    for(int i=k; i<v.size(); i++){
        v[j] = q.top();
        q.pop();
        q.push(v[i]);
        j++;
    }
    while(!q.empty()){
        v[j] = q.top();
        q.pop();
        j++;
    }
    return;
}
//***********************************************************************

//K-Smallest Element
vector<int> ksmallestelement(vector<int>& v, int k){
    priority_queue<int> q;
    for(int i=0; i<k; i++){
        q.push(v[i]);
    }

    for(int i=k; i<v.size(); i++){
        if(v[i] < q.top()){
            q.pop();
            q.push(v[i]);
        }
    }
    vector<int> svector;
    for(int i=0; i<k; i++){
        svector.push_back(q.top());
        q.pop();
    }
    return svector;
}

//Syntax for Min Priority Queue (inbuilt)
/*
priority_queue<int, vector<int>, greater<int>> q;
*/

//Assignment 
//Questions 0
bool checkMaxHeap(vector<int> v){
    for(int i=1; i<v.size(); i++){
        int pi = (i-1)/2;
        if(v[i] > v[pi]){
            return false;
        }
    }
    return true;
}

//Question 1
int kthlargest(vector<int>& v, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(v[i]);
    }
    for(int i=k; i<v.size(); i++){
        if(v[i] > pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}



//Question 2
typedef pair<int, pair<int, int>> trip;    // <Value <Index, Which arr>>

vector<int> mergeksortedarrays(vector<vector<int>>& kArrays, int k){

    priority_queue<trip, vector<trip>, greater<trip>> pq;
    //

    for(int i=0; i<k; i++){      //You can also use "auto" with an extra variable for i
        trip t;
        t.first = kArrays[i][0];           //first = value
        t.second.first = 0;                //second.first = index
        t.second.second = i;               //second.second = which array
        pq.push(t);
    }

    vector<int> ans;
    while(!pq.empty()){
        trip t = pq.top();
        pq.pop();
        ans.push_back(t.first);
        if(t.second.first+1 < kArrays[t.second.second].size()){ //For better readibility you can use Class and Object instead of pair
            trip nt = t;
            nt.first = kArrays[t.second.second][t.second.first+1];
            nt.second.first++;
            pq.push(nt);
        }
    }
    return ans;
}

//With the help of class
class triplet{
    public:
    int val;
    int ind;
    int narr;
    triplet(int val , int ind, int narr){
        this->ind = ind;
        this->val = val;
        this->narr = narr;
    }

};

struct cmp{
    bool operator()(triplet& t1, triplet& t2){
        return (t1.val > t2.val);
    }
};


vector<int> mergeKArrays(vector<vector<int>> arr, int K){                //YT - Hello World - geeksforgeeks
    priority_queue<triplet, vector<triplet>, cmp> pq;
    for(int i=0; i<K; i++){
        triplet t(arr[i][0], 0, i);
        pq.push(t);
    }

    vector<int> ans;
    while(!pq.empty()){
        triplet t=pq.top();
        pq.pop();
        ans.push_back(t.val);
        if(t.ind+1 < arr[t.narr].size()){
            t.val = arr[t.narr][t.ind+1];
            t.ind++;
            pq.push(t);
        }
    }
    return ans;
}
//**************************************************************

//Question3 

void runningmedian(vector<int>& v){
    priority_queue<int> pMax;
    priority_queue<int, vector<int>, greater<int>> pMin;
    pMax.push(v[0]);
    cout<<pMax.top()<<"\n";
    for(int i=1; i<v.size(); i++){
        if(v[i] < pMax.top()){
            pMax.push(v[i]);
        }else{
            pMin.push(v[i]);
        }
        int ans = pMin.size()-pMax.size();
        if(ans == -2 ){
            pMin.push(pMax.top());
            pMax.pop();
        }
        if(ans == 2){
            pMax.push(pMin.top());
            pMin.pop();
        }
        if(pMin.size() > pMax.size()){
            cout<<pMin.top()<<"\n";
        }else if(pMax.size() > pMin.size()){
            cout<<pMax.top()<<"\n";
        }else{
            cout<<((pMax.top()+pMin.top())/2)<<"\n";
        }

    }
    return;
}

//Last Question - Buy the ticket 

int buyticket(int n, vector<int>& v, int k){
    int time = 0;
    int myprio = v[k];
    int i = 0;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i]);
    }
    while(pq.top() != myprio || i != k){
        if(v[i] == pq.top()){
            pq.pop();
            time++;
        }
        i++;
        if(i == n){
            i = 0;
        }
    }
    time++;
    return time;
}

//

//YT-Hello World, Top K frequent elements - Brute force   :by Me

//Accepted-Leetcode
vector<int> topkfrequent(vector<int>& v, int k){
    unordered_map<int, int> m;
    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }
    vector<int> ans;
    while(k--){
        int hfreq = 0;
        int mostfreq = INT32_MIN;
        unordered_map<int, int>::iterator it = m.begin();
        while(it != m.end()){
            if(it->second > hfreq){
                mostfreq = it->first;
                hfreq = it->second;
            }
            it++;
        }
        m[mostfreq] = 0;
        ans.push_back(mostfreq);
    }
    return ans;
}


//by YT-Hello World Using Heap   // Better solution    ** Use "auto" and "make_pair" - It's Fast
typedef pair<int, int> pi;
vector<int> topkfrequent2(vector<int>& nums, int k){
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++){    //If you don't know auto keyword
        m[nums[i]]++;
    }
    /*for(auto x: nums){
        m[x]++;
    }*/

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    unordered_map<int, int>::iterator it = m.begin(); //If you don't know auto 
    while(it != m.end()){
        pi p;                    //If you don't know make_pair
        p.first = it->second;
        p.second = it->first;
        //pq.push(make_pair(it->second, it->first));
        pq.push(p);
        if(pq.size() > k){
            pq.pop();
        }
    }

    /*for(auto x: m){
        pq.push(make_pair(x.second, x.first));
        if(pq.size() > k){
            pq.pop();
        }
    }*/
    vector<int> ans;
    while (!pq.empty()){
        pi top = pq.top();
        ans.push_back(top.second);
        pq.pop();
    }
    return ans;
}


int main(){

    // Common Input code
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    /*int k;
    cin>>k;
    //ksortedarr(v, k);
    vector<int> na = ksmallestelement(v, k);
    for(int i=0; i<k; i++){
        cout<<na[i]<<" ";
    }*/

    //Assignment 
    //Question 0
    /*if(checkMaxHeap(v)){
        cout<<"True";
    }else{
        cout<<"False";
    }*/

    //Question 1
    /*int k;
    cin>>k;
    cout<<kthlargest(v, k);*/

    //Question 2 //Executed in GFG // try to take input in 2D arrays

    //Question 3
    //runningmedian(v);

    //Question 4
    int k;
    cin>>k;
    cout<<buyticket(n, v, k);
    return 0;
}
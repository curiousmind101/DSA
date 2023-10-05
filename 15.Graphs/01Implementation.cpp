#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *track){       //sv - starting vertex
    cout<<sv<<"\n";
    track[sv] = true;
    for(int i=0; i<n; i++){                                   //same vertex
        if(sv == i){
            continue;
        }
        
        if(edges[sv][i] == 1){
            if(track[i]){                                    //Visited/Printed verex                        
            continue;
            }
            printDFS(edges, n, i, track);
        }
    }
    return;
}

void printBFS(int **edges, int n, int sv, bool *track){      
    queue<int> pendingvertices;
    pendingvertices.push(sv);
    track[sv] = true;
    while(pendingvertices.size() != 0){
        int front = pendingvertices.front();
        pendingvertices.pop();
        cout<<front<<endl;
        for(int i=0; i<n; i++){
            if(front == i){
                continue;
            }
            if(edges[front][i] == 1){
                if(track[i]){
                    continue;
                }
                pendingvertices.push(i);
                track[i] = true;
            }
        }
    }
    return;
}

void printBFS(int **edges, int n){            
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    queue<int> pendingvertices;
    pendingvertices.push(0);                      //starting with 0
    track[0] = true;
    while(pendingvertices.size() != 0){
        int front = pendingvertices.front();
        pendingvertices.pop();
        cout<<front<<endl;
        for(int i=0; i<n; i++){
            if(front == i){
                continue;
            }
            if(edges[front][i] == 1){
                if(track[i]){
                    continue;
                }
                pendingvertices.push(i);
                track[i] = true;
            }
        }
    }
    return;
}

void DFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

void BFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

//Has Path
bool HasPathDFS(int **edges, int n, int v1, int v2, bool *track){       //DFS
    //Base Case
    if(edges[v1][v2] == 1){
        return true;
    }
    track[v1] = true;
    int j;
    for(j=0; j<n; j++){
        if(!track[j]){
            break;
        }
    }
    if(j == n){
        return false;
    }
    for(int i=0; i<n; i++){
        if(i == v1){
            continue;
        }
        if(edges[v1][i]==1  && !track[i]){
            return HasPathDFS(edges, n, i, v2, track);
        }
    }
    return false;
}

bool HasPathBFS(int **edges, int n, int v1, int v2, bool *track){
    queue<int> pendingvertices;
    pendingvertices.push(v1);
    while(pendingvertices.size() != 0){
        int front = pendingvertices.front();
        pendingvertices.pop();
        if(edges[front][v2] == 1){
            return true;
        }
        track[front] = true;
        int j;
        for(j=0; j<n; j++){
            if(!track[j]){
            break;
            }
        }
        if(j == n){
            return false;
        }

        for(int i = 0; i<n; i++){
            if(i == front){
                continue;
            }
            if(edges[front][i] == 1 && !track[i]){
                pendingvertices.push(i);
            }
        }
    }
    return false;
}

void HasPath(int **edges, int n){
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    int v1, v2;
    cin>>v1>>v2;
    if(HasPathBFS(edges, n, v1, v2, track)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    delete [] track;
}

vector<int> getPathDFS(int **edges, int n, int v1, int v2, bool *track){
    vector<int> path;
    if(v1 == v2){
        path.push_back(v1);
        return path;
    }
    track[v1] = true;
    int j;
    for(j = 0; j<n; j++){
        if(!track[j]){
            break;
        }
    }
    if(j == n){
        return path;
    }
    for(int i=0; i<n; i++){
        if(i == v1){
            continue;
        }
        if(edges[v1][i]==1  && !track[i]){
            vector<int> ans = getPathDFS(edges, n, i, v2, track);
            if(ans.size() != 0){
                ans.push_back(v1);
                return ans;
            }
        }
    }
    return path;
}
bool getPathDFS(int **edges, int n, int v1, int v2, vector<int> &path, bool *track){
    if(v1 == v2){
        path.push_back(v1);
        return true;
    }
    track[v1] = true;
    int j;
    for(j=0; j<n; j++){
        if(!track[j]){
            break;
        }
    }
    if(j == n){
        return false;
    }
    for(int i=0; i<n; i++){
        if(i == v1){
            continue;
        }
        if(edges[v1][i]==1  && !track[i]){
            if(getPathDFS(edges, n, i, v2, path, track)){
                path.push_back(v1);
                return true;
            }
        }
    }
    return false;
}

vector<int> getPathBFS(int **edges, int n, int v1, int v2, bool *track){
    vector<int> path;
    if(v1 == v2){
        path.push_back(v1);
        return path;
    }
    queue<int> pendingvertices;
    pendingvertices.push(v1);
    unordered_map<int, int> mymap;
    while(pendingvertices.size() != 0){
        int front = pendingvertices.front();
        pendingvertices.pop();
        if(front == v2){
            path.push_back(front);
            while(front != v1){
                path.push_back(mymap[front]);
                front = mymap[front];
            }
            return path;
        }
        track[front] = true;
        int j;
        for(j=0; j<n; j++){
            if(!track[j]){
                break;
            }
        }
        if(j == n){
           return path;
        }
        for(int i = 0; i<n; i++){
            if(i == front){
                continue;
            }
            if(edges[front][i] == 1 && !track[i]){
                pendingvertices.push(i);
                mymap[i] = front;
            }
        }
    }
    return path;
}

void getPath(int **edges, int n){
    int v1, v2;
    cin>>v1>>v2;
    vector<int> path;
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    //if(getPathDFS) - You can write
    path = getPathBFS(edges, n, v1, v2, track);
    for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
    }
    delete [] track;
    return;
}

bool isConnected(int **edges, int n, bool *track, int sv){
    track[sv]=true;
    int j;
    for(j=0; j<n; j++){
        if(!track[j]){
            break;
        }
    }
    if(j == n){
        return true;
    }
    for(int i=0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i]==1  && !track[i]){
            return isConnected(edges, n, track, i);
        }
    }
    return false;
}

void isConnected(int **edges, int n){
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    if(isConnected(edges, n, track, 0)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    delete [] track;
    return;
}

void printDFSn(int **edges, int n, int sv, bool *track){       //sv - starting vertex
    cout<<sv<<" ";
    track[sv] = true;
    for(int i=0; i<n; i++){                                   //same vertex
        if(sv == i){
            continue;
        }
        
        if(edges[sv][i] == 1){
            if(track[i]){                                    //Visited/Printed vertex                        
            continue;
            }
            printDFSn(edges, n, i, track);
            cout<<"\n";
        }
    }
    return;
}

void AllConnected(int **edges, int n){
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    for(int i=0; i<n; i++){                                   //same vertex   
        if(track[i]){                                         //Visited/Printed verex                        
            continue;
        }
        printDFSn(edges, n, i, track);
    }
    delete [] track;
    return;
}

int main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
       int f, s;
       cin>>f>>s;
       edges[f][s] = 1;
       edges[s][f] = 1;
    }
    bool *track = new bool[n];
    for(int i=0; i<n; i++){
        track[i] = false;
    }
    //printDFS(edges, n, 0);
    //printBFS(edges, n);
    /*cout<<"BFS"<<endl;
    BFS(edges, n);
    cout<<"DFS"<<endl;
    DFS(edges, n);*/
    //HasPath(edges, n);
    //getPath(edges, n);
    //isConnected(edges, n);
    AllConnected(edges, n);
    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    delete [] track;
    return 0;
}
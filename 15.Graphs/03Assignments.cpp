#include<iostream>
using namespace std;

void DFS(int **edges, int n, int sv, bool * visited){
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(sv == i){
            continue;
        }
        if(edges[sv][i] != 0  && !visited[i]){
            DFS(edges, n, i, visited);
        }
    }
    return;
}

int Island(int **edges, int n){
    bool * visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(visited[i]){
            continue;
        }
        if(!visited[i]){
            DFS(edges, n, i, visited);
            count++;
        }
    }
    delete [] visited;
    return count;  
}

int main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int j=0; j<n; j++){
        edges[j] = new int[n];
        for(int i=0; i<n; i++){
            edges[j][i] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int s, e;
        cin>>s>>e;
        edges[s][e] = 1;
    }
    cout<<Island(edges, n);
    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    return 0;
}
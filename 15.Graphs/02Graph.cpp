#include <bits/stdc++.h> 
using namespace std;

class edge{
    public:
    int weight;
    int source;
    int dest;
};

int findparent(int v, int *parent){
    if(parent[v] == v){
        return v;
    }
    return findparent(parent[v], parent);
}

bool compare(edge e1, edge e2){
    return (e1.weight < e2.weight);
}

void MST(edge *input, edge *output, int n, int e){                    //Kruskal Algorithm (Greedy-I)
    sort(input, input+e, compare);
    int * parent = new int[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    int count = 0;
    for(int i=0; count<n-1; i++){
        int sourceparent = findparent(input[i].source, parent);
        int destparent = findparent(input[i].dest, parent);
        if(sourceparent != destparent){
            output[count] = input[i];
            parent[sourceparent] = destparent;
            count++;
        }
    }
    for(int i=0; i<n-1; i++){
        if(output[i].source > output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<"\n";
        }else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<"\n";
        }
    }
    delete [] parent;
    return;
}

void MST2(int n, int **edges, edge * output){             //Not Working
    bool *visited = new bool[n];
    int *weight = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weight[i] = INT32_MAX;
    }
    weight[0] = 0;
    int count = 0;
    int currentVertex = 0;
    while (count<n-1){ 
        int minimum = INT32_MAX;
        int mini = INT32_MAX;
        visited[currentVertex] = true;
        for(int j=0; j<n; j++){
            if(edges[currentVertex][j] != 0 && !visited[j]){
                if(edges[currentVertex][j] < minimum){
                    weight[j] = min(weight[j], edges[currentVertex][j]);
                    minimum = edges[currentVertex][j];
                    mini = j;
                }
            }
        }
        output[count].source = currentVertex;
        output[count].dest = mini;
        output[count].weight = minimum;
        currentVertex = mini;
        count++;
    }
    for(int i=0; i<count; i++){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].dest<<"\n";
    }
    return;
}
int findMinVertex(int *weight, bool *visited, int n){
    int minvtx = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minvtx == -1 || weight[i] < weight[minvtx])){
            minvtx = i;
        }
    }
    return minvtx;
}
void MST3(int n, int **edges, edge * output){
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weight[i] = INT32_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    for(int i=0; i<n; i++){
        int minVtx = findMinVertex(weight, visited, n);
        visited[minVtx] = true;
        for(int j=0; j<n; j++){
            if(edges[minVtx][j] != 0 && !visited[j]){
                if(edges[minVtx][j] < weight[j]){
                    weight[j] = edges[minVtx][j];
                    parent[j] = minVtx;
                }
            }
        }
    }
    for(int i=1; i<n; i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    delete [] visited;
    delete [] weight;
    delete [] parent;
    return;
}

void DijktrasAlgo(int n, int **edges){
    bool *visited = new bool[n];
    int *distance = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        distance[i] = INT32_MAX;
    }
    distance[0] = 0;
    for(int i=0; i<n; i++){
        int minvtx = findMinVertex(distance, visited, n);
        cout<<minvtx<<" "<<distance[minvtx]<<endl;
        visited[minvtx] = true;
        for(int j=0; j<n; j++){
            if(edges[minvtx][j] != 0 && !visited[j]){
                if(edges[minvtx][j]+distance[minvtx] < distance[j]){
                    distance[j] = edges[minvtx][j]+distance[minvtx];
                }
            }
        }
    }
    delete [] visited;
    delete [] distance;
    return;
}

int main(){
    int n, e;
    cin>>n>>e;
    edge *input = new edge[e];
    /*for(int i=0; i<e; i++){
        int source, dest, weight;
        cin>>source>>dest>>weight;
        input[i].source = source;
        input[i].dest = dest;
        input[i].weight = weight;
    }*/
    edge *output = new edge[n-1];
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        edges[s][d] = w;
    }
    //MST3(n, edges, output);
    DijktrasAlgo(n, edges);
    delete [] input;
    delete [] output;
    for(int i=0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;
    return 0;
}
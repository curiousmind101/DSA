#include<iostream>
using namespace std;

int main(){

    int m, n;
    cin>>m>>n;
    int **p = new int*[m];     //p is the pointer of an array of pointers which are in heap
    for(int i=0; i<m; i++){    
        //int x;
        //cin>>x;
        //p[i] = new int[x];    it means you can take array of any length at any line
        p[i]= new int[n];      //p[i] is an element of the array of pointers and it stores the address of an array in heap
        for(int j=0; j<n; j++)
        {
            cin>>p[i][j];
        }
    }

    //Now this is how to access them
    for(int i=0; i<m; i++){    
        for(int j=0; j<n; j++)
        {
            cout<<p[i][j]<<" ";        
        }
        cout<<"\n";
    }

    for(int i=0; i<m; i++){
        delete [] p[i];        //this deletes the entire array in heap whose address it contains.
    }
    delete [] p;               //and this deletes the array of pointers in heap
    return 0;
}
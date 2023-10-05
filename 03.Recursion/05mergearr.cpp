#include<iostream>
#include<vector> 
using namespace std;


// To print the merged Array
void showarr(int arr3[], int size){
    for(int i=0; i<size; i++){
            cout<<arr3[i]<<" ";
    }
    cout<<endl;
}

//Function for merging arrays
void Merge2shortedarrys(int arr1[], int arr2[], int n, int m) {
    int sum= (n+m);
    int arr3[sum];
    int i = 0, j = 0;
    int k = 0;
    while( (i!=n) && (j!=m)) {
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

   while(i<n){
        arr3[k] = arr1[i];
        k++;
        i++;
    }

   while(j<m){
        arr3[k] = arr2[j];
        k++;
        j++;
    }
    cout<<endl;
    showarr(arr3, sum);
}

int main (){
    //taking input two arrays with their size
    int n, m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int j=0; j<m; j++){
        cin>>b[j];
    }

    //Calling merge function
    Merge2shortedarrys(a, b, n, m);
    return 0;
}
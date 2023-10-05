#include<iostream>
#include<vector> 
using namespace std;


// To print the merged Array
void showArr(int arr3[], int size){
    for(int i=0; i<size; i++){
            cout<<arr3[i]<<" ";
    }
    cout<<endl;
}

//Function for merging arrays
void merge2ShortedArrays(int arr1[], int arr2[], int n, int m) {
    int sum= (n+m); //sum of the sizes of two arrays
    int arr3[sum];  //array two contain merged sorted elements
    int i = 0;      //iterator for first array
    int j = 0;      //iterator for second array
    int k = 0;      //iterator for new array
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

   while(i<n){    // if some element left in the first array
        arr3[k] = arr1[i];  //OR  arr3[k++] = arr2[i++];
        k++;
        i++;
    }

   while(j<m){   //if some element left in the second array
        arr3[k] = arr2[j];  //OR  arr3[k++] = arr2[j++];
        k++;
        j++;
    }
    cout<<endl;
    showArr(arr3, sum);  //function to print sorted merged array
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
    merge2ShortedArrays(a, b, n, m);
    return 0;
}
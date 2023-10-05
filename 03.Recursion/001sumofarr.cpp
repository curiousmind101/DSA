#include<iostream>
using namespace std;

int sumofa(int arr[], int size){
    if(size == 0){
        return 0;
    }
    else{
        int smalloutput = sumofa(arr+1, size-1);
        return arr[0]+smalloutput;
    }
}

/*  with Iterator
int sumofarr(int arr[], int size){
    if(size==0){
        return 0;
    }
    int ans = 0;
    while(int i=0; i<size; i++){
        ans += arr[i];
    }
    return ans;
}
*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<sumofa(arr, n);
    return 0;
}
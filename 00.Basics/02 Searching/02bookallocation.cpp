#include <iostream>
using namespace std;

int ifpossible(int n, int arr[], int mid, int st){            //nlog(size)  base 2
    int stcount = 1;
    int noofpages = 0;
    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            return false;
        }
        if(arr[i]+noofpages > mid){
            stcount++;
            noofpages = arr[i];
            if(stcount>st){
                return false;
            }
        }else{
            noofpages += arr[i];
        }
    }
    return true;
}


int main() 
{
    /*******|taking input|******/
    int st;
    cin>>st;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    /***************************/

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int s = 0;
    int e = sum;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(ifpossible(n, arr, mid, st)){
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    cout<<ans;
	return 0;
}
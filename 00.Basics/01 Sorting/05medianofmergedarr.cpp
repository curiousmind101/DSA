#include<iostream>
#include<vector>

using namespace std;
// Run in GeeksForGeeks


void showarr(vector<int> ans){
    int s = ans.size();
    for(int i=0; i<s; i++){
        cout<<ans.at(i)<<" ";
    }
}


// Returns the median of merged Array
double random(vector<int> nums1, vector<int>nums2){
    int n=0, m=0;
    n = nums1.size();
    m = nums2.size();
    int i=0; 
    int j=0;
    int k=0;
    double a = 0;
    double b = 0;
    int mid = (n+m)/2;
    while((i!=n) && (j!=m) && k!= mid+1){
        if(nums1[i]<nums2[j]){
            if(k == mid-1){
                a = nums1[i];
            }
            if(k == mid){
                b = nums1[i];
            }
            i++;
            
        }
        else{
            if(k== mid-1){
                a = nums2[j];
            }
            if(k==mid){
                b = nums2[j];
            }
            j++;
        }
        k++;
        
    }
    for(; i!=n && k<mid+1; i++){
        if(k==mid-1){
        a = nums1[i];
        }
        if(k==mid){
        b = nums1[i];
        }
        k++;
    }
    
    for(; j!=m && k<mid+1; j++){
        if(k==mid-1){
        a = nums2[j];
        }
        if(k==mid){
        b = nums2[j];
        }
        k++;
    }
    if((m+n)%2==0){
        return ((a+b)/2);   // for even number of elements 
    }
    else{
        return b;          //  for odd number of elements 
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> nums1;
    vector<int> nums2;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    for(int j=0; j<m; j++){
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    cout<<random(nums1, nums2);
}
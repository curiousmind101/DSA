#include<iostream> 
using namespace std;

// This function do all the work so read with attention
int partition(int arr[], int l, int r){
    int count = l;
    //To find how many numbers arr smaller than our pivot element
    for(int i=(l+1); i<=r; i++){
        if(arr[i]<arr[l]){
            count++;
        }
    }

    //swaping pivot element to its correct position
    int swap = arr[count];
    arr[count] = arr[l];
    arr[l]=swap;
    
    int i=l;
    int j=r;
    // rearranging the numbers smaller than and greater than to their correct side
    while(i<count && j>count){
        while(arr[i]<arr[count] && i < count){   //check, before pivot elements are less than or not
            i++;
        }
        while(arr[j]>=arr[count] && j> count){  //check, after pivot elements are greater than or not
            j--;
        }
        if(arr[i]>=arr[count] && arr[j] < arr[count]){  //swap elements with incorrect side
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return count;  //pivot index
}

void quicksort(int arr[], int l, int r){
    if(l<r){
        int x = partition(arr, l, r); //finding pivot index
        quicksort(arr, l, (x-1));     //calling function for before pivot element
        quicksort(arr, (x+1), r);     //calling function for after pivot element
    }
    return;
}

int main(){

    //input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr, 0, (n-1));
    
    //printing sorted arra
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
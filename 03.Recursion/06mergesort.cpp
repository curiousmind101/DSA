#include <iostream>
using namespace std;

// Function to merge left and right subarrays of arr.
void mergeTwoSortedArray(int leftSubArray[], int rightSubArray[], int arr[], int n, int m)
{
    // i is for leftSubArray, j is for rightSubArray, k is for arr
     int i = 0;
     int j = 0;
     int k = 0;


    while (i < n && j < m) {
        if (leftSubArray[i] <= rightSubArray[j]) {
            arr[k] = leftSubArray[i];
            i++;
        }
        else {
            arr[k] = rightSubArray[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of leftSubArray[] 
    while (i < n) {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }

    // copy remaining elements of rightSubArray
    while (j < m) {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    } 
}


void mergeSort(int arr[], int size){
	//this is a special case - it means we don't have an array to sort. Mind that the array size can never be less than 0
	if (size == 0) {
		return;
}

     // if only one element is present in arr then we don't need to divide array further as one element is sorted in itself.
       if(size == 1)
       {
        	return;
       }
    // create leftSubArray and rightSubArray - and copy the elements as it is from arr.
        int n  = size / 2;
        int m = size - n;

        int leftSubArray[n];
        int rightSubArray[m];
        
   //pointer for arr
        int k = 0;

        for(int i = 0; i < n; i++)
        {
            leftSubArray[i] = arr[k];
            k++;
        }

        for(int j = 0; j < m; j++)
        {
            rightSubArray[j] = arr[k];
            k++;
        }
    
     //call mergeSort on left subarray
        mergeSort(leftSubArray, n);
    
     //call mergeSort on right subarray
        mergeSort(rightSubArray, m);
    
     //merging the two sorted subarrays back to the original one
        mergeTwoSortedArray(leftSubArray, rightSubArray, arr, n, m);
        return;
}

int main()
{
    int size;
    cin>>size;

    //OR
    /*int arr[] = { 14, 17, 22, 4, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);*/
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    mergeSort(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
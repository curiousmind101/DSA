#include <iostream>
#include "Linked_list.cpp"
using namespace std;

Node* append(Node* head, int N){
    Node *temp = head;
    int listsize = listLength(head);
    for(int i=0; i<(listsize-N)-1; i++){
        temp = temp->next;
    }
    Node *ntemp = temp->next;
    temp->next = NULL;
    temp = ntemp;
    while(ntemp->next != NULL){
        ntemp = ntemp->next;
    }
    ntemp->next = head;
    head = temp;
    return head;
}

int main(){
    int N;
    cin>>N;
    Node *head = takeinput();
    head = append(head, N);
    printfun(head);
    return 0;
}

// Function to merge left and right subarrays of arr.
/*void mergeTwoSortedArray(char leftSubArray[], char rightSubArray[], char arr[], int n, int m)
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


void mergeSort(char arr[], int size){
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

        char leftSubArray[n];
        char rightSubArray[m];
        
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
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}*/
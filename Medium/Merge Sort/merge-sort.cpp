//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
   void merge(int arr[], int l, int m, int r)
    {
         
         int leftsize=m-l+1;
         int rightsize=r-m;
         
         int *leftarr=new int[leftsize];
         int *rightarr=new int[rightsize];
         
         for(int i=0;i<leftsize;i++){
            leftarr[i]=arr[i+l];
         }
         
         for (int i=0;i<rightsize;i++){
             rightarr[i]=arr[m+1+i];
         }
         
         int i=0;int j=0;int k=l;
         
         while(j<rightsize && i<leftsize){
             if(rightarr[j]<leftarr[i]){
                 arr[k]=rightarr[j];
                 j++;
                 k++;
             }
             else{
                 arr[k]=leftarr[i];
                 i++;
                 k++;
             }
         }
       // edge case      
     while(j<rightsize){
        arr[k]=rightarr[j];
        j++;
        k++;
             
         }
             
          while(i<leftsize){
         arr[k]=leftarr[i];
         i++;
         k++;
         }
         //free memory
         delete[] leftarr;
         delete[] rightarr;
    }
    
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        //base case
        if(l>=r)
        return;
        // array divide into two part left and right
        // so calculate mid
        int mid=l+(r-l)/2;
        // recursive call for sort left array
        mergeSort(arr,l,mid);
        //recursive call for sort right array
        mergeSort(arr,mid+1,r);
        // recursive call for merge two sorted array
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
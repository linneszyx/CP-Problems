//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
          if(num==1) return arr[0];
        int sum=0;
        int flag=0;
        for(int i=0;i<num;i++){
            if(arr[i]>0)flag=1;
            sum+=arr[i];
        }
        if(flag==0) return *max_element(arr,arr+num);
        int i=0,j=0;
        int ans=0;
        int add=0;
        while(i<num){   //circular max sum
            if(j<num) add+=arr[j++];
            else add-=arr[i++];
            while(add>0 && i<j){
                add-=arr[i++];
            }
            ans=max(ans,sum-add);
        }
        int normal=0;
        i=0,j=0;
        add=0;
        while(i<num){   //linear max sum
            if(j<num) add+=arr[j++];
            else add-=arr[i++];
            while(add<0 && i<j){
                add-=arr[i++];
            }
            normal=max(normal,add);
        }
        return max(normal,ans);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool  mycmp(Job J1,Job J2) {
        
        if(J1.dead != J2.dead)
             return J1.dead < J2.dead ;
             
          return J1.profit > J2.profit;
        
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,mycmp);
        int curr=0;
        int p=0 ;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n;i++) {
           
            Job J1=arr[i];
            if(curr<J1.dead) {
                curr++;
                pq.push(J1.profit);
            }
            else if(curr==J1.dead and pq.top()<J1.profit){
                pq.pop();
                pq.push(J1.profit);
            }
        }
        
        while(!pq.empty()) {
            p+=pq.top();
            pq.pop();
        }
        
        return {curr , p};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
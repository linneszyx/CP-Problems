//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> a,b;
    double median;
    void insertHeap(int &x)
    {
        a.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int temp = a.top();
        a.pop();
        b.push(-1*temp);
        if(b.size()>a.size()){
            temp = b.top();
            b.pop();
            a.push(-1*temp);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
         if(a.size() != b.size())
            median = (double)a.top();
        else{
            median = (double)((a.top() * 1.0 - b.top() * 1.0)/2);
        }
        
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
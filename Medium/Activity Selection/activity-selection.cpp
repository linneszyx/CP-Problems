//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef pair<int, int> pii;
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
     
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pii> activities;
        activities.resize(n);
        for(int i =0;i < n; i++)
        {
            activities[i].first = start[i];
            activities[i].second = end[i];
        }
        
        sort(activities.begin(), activities.end(),
        [](const pii p1, const pii p2)
        {
            if(p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        }
        );
        
        int lastEndTime = activities[0].second;
        int ans = 1;
        
        for(int i =1; i< n; i++)
        {
            if(activities[i].first > lastEndTime)
            {
                ans++;
                lastEndTime = activities[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
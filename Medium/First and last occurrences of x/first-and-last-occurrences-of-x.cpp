//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> list;
        list.push_back(-1);
        list.push_back(-1);
        int cnt = -1;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == x)
            {
                cnt += 1;
                if(cnt == 0)
                {
                    list.insert(list.begin(), i);
                    list.insert(list.begin()+1, i);
                }
                else
                    list.insert(list.begin()+1, i);
            }
        }
        return list;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
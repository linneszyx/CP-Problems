//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
              vector<bool> new_A(26,false);
            vector<bool> new_B(26,false);
            string ans;
            for(int i=0;i<A.size();i++)
            {
                new_A[A[i]-'a']=true;
            }
            for(int j=0;j<B.size();j++)
            {
                new_B[B[j]-'a']=true;
            }
            for(int k=0;k<26;k++)
            {
                if(new_A[k]!=new_B[k])
                {
                    ans+= char('a'+k);
                }
            }
            if(ans.size()==0)
                return "-1";
            return ans;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
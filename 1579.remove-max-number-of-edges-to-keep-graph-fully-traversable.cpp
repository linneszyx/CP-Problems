/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
public:
   
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=i;
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==3)
            {
                int a=edges[i][1];
                int b=edges[i][2];
                int pa=dp[a];
                int pb=dp[b];
                while(pa!=dp[pa])
                    pa=dp[pa];
                while(pb!=dp[pb])
                    pb=dp[pb];
                if(pa==pb)
                    ans++;
                else
                    dp[pa]=pb;
            }
        }
        int dp1[n+1];
        for(int i=0;i<=n;i++)
            dp1[i]=dp[i];
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            {
                int a=edges[i][1];
                int b=edges[i][2];
                int pa=dp[a];
                int pb=dp[b];
                while(pa!=dp[pa])
                    pa=dp[pa];
                while(pb!=dp[pb])
                    pb=dp[pb];
                if(pa==pb)
                    ans++;
                else
                    dp[pa]=pb;
            }
        }
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==2)
            {
                int a=edges[i][1];
                int b=edges[i][2];
                int pa=dp1[a];
                int pb=dp1[b];
                while(pa!=dp1[pa])
                    pa=dp1[pa];
                while(pb!=dp1[pb])
                    pb=dp1[pb];
                if(pa==pb)
                    ans++;
                else
                    dp1[pa]=pb;
            }
        }
        int c1=0,c2=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==i)
                c1++;
            if(dp1[i]==i)
                c2++;
        }
        if(c1>1||c2>1)
            return -1;
        return ans;
    }
};
// @lc code=end


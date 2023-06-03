//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int n1  = S1.size();
        int n2  = S2.size();
        int n3  = S3.size();
        int sum1 = 0, sum2 = 0, sum3 = 0;
        for(int i = 0; i < n1; i++)
            sum1 += S1[i];
        for(int i = 0; i < n2; i++)
            sum2 += S2[i];
        for(int i = 0; i < n3; i++)
            sum3 += S3[i];
        int top1 = 0, top2 = 0, top3 = 0;
        while(top1 < n1 && top2 < n2 && top3 < n3){
            if(sum1 == sum2 && sum2 == sum3)
                return sum1;
            if(sum1 >= sum2 && sum1 >= sum3)
                sum1 -= S1[top1++];
            else if(sum2 >= sum1 && sum2 >= sum3)
                sum2 -= S2[top2++];
            else if(sum3 >= sum1 && sum3 >= sum2)
                sum3 -= S3[top3++];
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
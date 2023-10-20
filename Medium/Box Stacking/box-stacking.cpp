//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {      vector<int>heightnew;
        vector<int>widthnew;
        vector<int>lengthnew;
        int i=0;
        vector<pair<int,int>>v;
        int j=0;
        while(i<n)
        {
            heightnew.push_back(height[i]);
            if(length[i]>width[i])
            {
                widthnew.push_back(width[i]);
                lengthnew.push_back(length[i]);
            }
            else
            {
                widthnew.push_back(length[i]);
                lengthnew.push_back(width[i]);            
            }
            v.push_back({length[i]*width[i], j});
            j++;
            heightnew.push_back(length[i]);
            if(height[i]>width[i])
            {
                widthnew.push_back(width[i]);
                lengthnew.push_back(height[i]);
            }
            else
            {
                widthnew.push_back(height[i]);
                lengthnew.push_back(width[i]);            
            }
            v.push_back({height[i]*width[i], j});
            j++;
            heightnew.push_back(width[i]);
            if(length[i]>height[i])
            {
                widthnew.push_back(height[i]);
                lengthnew.push_back(length[i]);
            }
            else
            {
                widthnew.push_back(length[i]);
                lengthnew.push_back(height[i]);            
            }
            v.push_back({height[i]*length[i], j});
            j++;
            i++;
        }
        sort(v.begin(), v.end());
        i=0;
        vector<int>height1(3*n);
        vector<int>width1(3*n);
        vector<int>length1(3*n);
        while(i<v.size())
        {
            height1[i]=heightnew[v[i].second];
            width1[i]=widthnew[v[i].second];
            length1[i]=lengthnew[v[i].second];
            i++;
        }
        vector<int>yo(3*n, 0);
        i=0;
        while(i<3*n)
        {
            yo[i]=height1[i];
            i++;
        }
        i=0;
        int max=0;
        while(i<3*n)
        {
            j=0;
            while(j<i)
            {
                if(length1[i]>length1[j] && width1[i]>width1[j] && height1[i]+yo[j]>yo[i])
                {
                    yo[i]=height1[i]+yo[j];
                }
                j++;
            }
            if(yo[i]>max) max=yo[i];
            i++;
        }
        return max;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends
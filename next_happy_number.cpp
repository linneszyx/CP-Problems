//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool solve(int input){
        if(input==1 || input==7) return true;
        if(input<10) return false;
        int x,temp=0;
        while (input!=0)
        {
            x = input%10;
            temp += x*x;
            input = input/10;
        }
        input=temp;
        return solve(input);
    }
    int nextHappy(int N){
        // code here
       int x = 0;
       int input = N + 1;
       while(x==0){
        solve(input);
        if(solve(input)==true){
            return input;
        }
        else{
            input+=1;
        }
       }
       return -1;
    }
   
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
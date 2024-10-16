//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
      int ch=2;
      for(int i=0,p=1;i<(arr.size()+1)/2;i+=1,p+=1){
          if(p!=arr[i] and ch) {swap(arr[i],arr[arr[i]-1]);ch--;}
      }
      return (ch==2) or (ch==0 and is_sorted(arr.begin(),arr.end()));
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends
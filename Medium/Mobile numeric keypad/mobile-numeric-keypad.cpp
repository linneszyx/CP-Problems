//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long getCount(int n) {
        map<string,vector<int>> mapping;
        mapping["1"]=vector<int>({1,2,4});
        mapping["2"]=vector<int>({1,2,3,5});
        mapping["3"]=vector<int>({2,3,6});
        mapping["4"]=vector<int>({1,5,7,4});
        mapping["5"]=vector<int>({6,2,4,8,5});
        mapping["6"]=vector<int>({6,3,5,9});
        mapping["7"]=vector<int>({8,7,4});
        mapping["8"]=vector<int>({7,5,9,8,0});
        mapping["9"]=vector<int>({9,6,8});
        mapping["0"]=vector<int>({0,8});
        vector<vector<pair<int,long long>>> freqMap(n);
        for(int i=0;i<10;i++){
            freqMap[0].push_back(pair<int,long long>({i,1}));
        }
        for(int i=2;i<=n;i++){
            //vector<pair<int,long long>> freqMap[i-1];
            for(int j=0;j<10;j++){
                freqMap[i-1].push_back(pair<int,long long>({j,0}));
            }
            for(int k=0;k<10;k++){
                vector<int> vec=mapping.at(to_string(k));
                for(int l=0;l<vec.size();l++){
                    freqMap[i-1][vec[l]].second+=freqMap[i-2][k].second;
                }
            }
        }
        long long sum=0;
        for(int i=0;i<10;i++){
            sum+=freqMap[n-1][i].second;
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
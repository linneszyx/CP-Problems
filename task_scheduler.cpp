//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int freq[26] = {0};
        for (int i = 0; i < N; i++) {
            freq[tasks[i] - 'A']++;
        }
        sort(freq, freq + 26, greater<int>());
        int maxFreq = freq[0];
        int idleTime = (maxFreq - 1) * K;
        for (int i = 1; i < 26; i++) {
            idleTime -= min(maxFreq - 1, freq[i]);
        }
        idleTime = max(0, idleTime);
        return idleTime + N;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
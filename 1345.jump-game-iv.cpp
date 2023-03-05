/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (43.82%)
 * Likes:    3220
 * Dislikes: 110
 * Total Accepted:    119.6K
 * Total Submissions: 255K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) return ans;
                if (cur - 1 >= 0 && !visited[cur - 1]) {
                    q.push(cur - 1);
                    visited[cur - 1] = true;
                }
                if (cur + 1 < n && !visited[cur + 1]) {
                    q.push(cur + 1);
                    visited[cur + 1] = true;
                }
                for (int j = 0; j < m[arr[cur]].size(); j++) {
                    int next = m[arr[cur]][j];
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
                m[arr[cur]].clear();
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end


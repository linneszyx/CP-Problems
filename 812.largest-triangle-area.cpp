/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 *
 * https://leetcode.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (60.05%)
 * Likes:    456
 * Dislikes: 1491
 * Total Accepted:    39.8K
 * Total Submissions: 66.3K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * Given an array of points on the X-Y plane points where points[i] = [xi, yi],
 * return the area of the largest triangle that can be formed by any three
 * different points. Answers within 10^-5 of the actual answer will be
 * accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2.00000
 * Explanation: The five points are shown in the above figure. The red triangle
 * is the largest.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,0],[0,0],[0,1]]
 * Output: 0.50000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= points.length <= 50
 * -50 <= xi, yi <= 50
 * All the given points are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double area(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p1[1] * p2[0] - p2[1] * p3[0] - p3[1] * p1[0]);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int r = points.size();
        double max_area = 0;
        for (int i = 0; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                for (int k = j + 1; k < r; k++) {
                    max_area = max(max_area, area(points[i], points[j], points[k]));
                }
            }
        }
        return max_area;
    }
};
// @lc code=end


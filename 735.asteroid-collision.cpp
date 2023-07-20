/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0 || res.empty() || res.back() < 0) {
                res.push_back(asteroids[i]);
            } else if (res.back() <= -asteroids[i]) {
                if (res.back() < -asteroids[i]) --i;
                res.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end


#define vi vector<int>
#define vii vector<vi>
class Solution {
public:
    void ff(vi& candidates, int target, vi curcomb, int cursum, int curidx,
            vii& res) {
        if (cursum > target)
            return;
        if (cursum == target) {
            res.push_back(curcomb);
            return;
        }
        for (int i = curidx; i < candidates.size(); i += 1) {
            curcomb.push_back(candidates[i]);
            cursum += candidates[i];
            ff(candidates, target, curcomb, cursum, i, res);
            curcomb.pop_back();
            cursum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vii res;
        vi curcomb;
        ff(candidates, target, curcomb, 0, 0, res);
        return res;
    }
};
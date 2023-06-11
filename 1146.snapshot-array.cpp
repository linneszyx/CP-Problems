/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
public:
int snap_id = 0;
    vector<vector<pair<int,int>>> arr;

    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        if(arr[index].empty() || arr[index].back().first != snap_id)
            arr[index].push_back({snap_id, val});
        else
            arr[index].back().second = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), snap_id, [](int val, const pair<int,int>& p){
            return val < p.first;
        });
        if(it == arr[index].begin())
            return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end


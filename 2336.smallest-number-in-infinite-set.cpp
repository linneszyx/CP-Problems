/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
    map<int, int> m;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1002; i++) {
            m[i]++;
        }
    }
    
    int popSmallest() {
      int res = m.begin()->first;
        m.erase(m.begin());
        return res;
    }
    
    void addBack(int num) {
        m[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end


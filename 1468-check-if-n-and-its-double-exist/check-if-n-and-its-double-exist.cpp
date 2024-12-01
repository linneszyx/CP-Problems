class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for(int num : arr) {
            if(seen.count(num*2) or (num%2==0 and seen.count(num/2))) return true;
            seen.insert(num);
        }
        return false;
    }
};
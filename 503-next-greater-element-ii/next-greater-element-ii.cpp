class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i-=1) 
        {
            while(!st.empty() and st.top()<=nums[i%n]) st.pop();
            if(!st.empty() and st.top()>=nums[i%n]) v[i%n] = st.top();
            st.push(nums[i%n]);
        }
        return v;
    }
};
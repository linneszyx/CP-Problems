class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> x(n2,-1);
        map<int,int> mp;
        stack<int> st;
        for(int i=n2-1;i>=0;i--) {
            while(!st.empty() and st.top()< nums2[i]) st.pop();
            if(!st.empty() and st.top()>nums2[i])  x[i] = st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n2;i+=1) mp[nums2[i]] = x[i];
        for(int i=0;i<n1;i+=1) nums1[i] = mp[nums1[i]];
        return nums1;
    } 
};
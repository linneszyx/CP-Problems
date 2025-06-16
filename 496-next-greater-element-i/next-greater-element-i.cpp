class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // vector<int> x(n2,-1);
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=n2-1;i>=0;i--) {
            while(!st.empty() and st.top()< nums2[i]) st.pop();
            if(!st.empty() and st.top()>nums2[i])  mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;i+=1){ if(mp.count(nums1[i])>0) nums1[i] = mp[nums1[i]]; else nums1[i] = -1;}
        return nums1;
    } 
};
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(s=="") return 0;
        stack<int> stk;
        stk.push(-1);
        int depth = 0;
        for(int i=0;i<n;i+=1)
        {
            if(s[i]=='(') {
                stk.push(i);
            }
            else {
                 stk.pop();
                if(stk.empty())
                stk.push(i);
               else depth = max(depth,i-stk.top());
            }
        }
        return depth;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> stk;
     for(string &s : tokens) {
        if(s.size()>1 or isdigit(s[0]))
        stk.push(stoi(s));
       else 
       { int n2 = stk.top();
        stk.pop();
        int n1 = stk.top();
        stk.pop();
        switch(s[0]) {
            case '+' : stk.push(n1+n2);
            break;
            case '-' : stk.push(n1-n2);
            break;
            case '*' : stk.push(n1*n2);
            break;
            case '/' : stk.push(n1/n2);
            break;
        }}
    }
        return stk.top();
     }
};
class Solution {
public:
    string clearDigits(string s) {
        string st;
        for(char c  : s) {
            if(isdigit(c)) {
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(c);
        }
        return st;
    }
};
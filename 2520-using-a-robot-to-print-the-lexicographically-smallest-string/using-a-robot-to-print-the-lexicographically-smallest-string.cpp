class Solution {
public:
char f(vector<int>&v) {
    for(int i=0;i<26;i+=1) if(v[i]) return 'a'+i;
    return 'a';
}
    string robotWithString(string s) {
       string t = "";
       stack<char> st;
        vector<int> v(26);
        for(char ch : s) v[ch-'a']++;
        for(char ch : s) {
            st.push(ch);
            v[ch-'a']--;
            while(!st.empty() and st.top() <=f(v)) {
                t+=st.top();
                st.pop();
            }
        }
while(!st.empty()) {
    t+=st.top();
    st.pop();
}
return t;

    }
};
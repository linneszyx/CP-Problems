#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll ss=0;
        int b=0;
        for(int i=0;i<s.length();i+=1) {
            if(s[i]=='0') {
                ss+=(ll)b;
            }
            else b++;
        }
        return ss;
    }
};
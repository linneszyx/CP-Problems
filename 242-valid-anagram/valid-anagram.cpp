class Solution {
public:
    bool isAnagram(string s, string t) {
         int s1 = s.length();
        int t1 = t.length();
        if (s1 != t1)
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};
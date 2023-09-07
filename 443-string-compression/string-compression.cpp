class Solution {
public:
    int compress(vector<char>& chars) {
          int res = 0;
        int i = 0;
        while (i < chars.size()) {
            int j = i;
            while (j < chars.size() && chars[j] == chars[i]) {
                j++;
            }
            chars[res++] = chars[i];
            if (j - i > 1) {
                string cnt = to_string(j - i);
                for (char c : cnt) {
                    chars[res++] = c;
                }
            }
            i = j;
        }
        return res;
    }
};
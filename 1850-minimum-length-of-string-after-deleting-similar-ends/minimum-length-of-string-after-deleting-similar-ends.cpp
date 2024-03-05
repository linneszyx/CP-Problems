class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right and s[left]==s[right]){
            char ch = s[left];
            while(left<=right and s[left]==ch) left++;
            while(right>=left and s[right]==ch) right--;

        }
        return right-left+1;
    }
};
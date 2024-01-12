class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        int vc = 0;
        int midx = s.length()/2;
        for(int i=0;i<midx;i+=1)
        {
            char cA = s[i];
            char cB = s[midx+i];
            if(v.count(cA)) vc++;
            if(v.count(cB)) vc--;
        }
        return vc==0;
    }
};
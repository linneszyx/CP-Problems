class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> v;
        vector<int> p;
        for(int i=0;i<n;i+=1){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U'
            )
                {
                    v.push_back(s[i]);
                    p.push_back(i);
                }
        }
        sort(v.begin(),v.end());
        string ans = s;
        for(int i=0;i<p.size();i+=1) ans[p[i]] = v[i];
        return ans;
    }
};
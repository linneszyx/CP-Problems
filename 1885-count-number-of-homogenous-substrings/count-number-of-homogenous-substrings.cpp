class Solution {
public:
    int countHomogenous(string s) {
        long long res  = 0;
        int start = 0;
        for(int i=0;i<s.size();i+=1){
            if(s[i]!=s[start]){
                int app = i-start;
                while(app>0){
                    res+=app;
                    app--;
                }
                start=i;
            }
        }
        int app = s.size()-start;
        while(app>0) {
            res+=app;
            app--;
        }
        return static_cast<int>(res%1000000007);
    }
};
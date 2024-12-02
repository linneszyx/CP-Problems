#define vi vector<int>
class Solution {
public:
vi lps;
void preKMP(const string &pattern) {
    int len = 0;
    const int n = pattern.size();
    lps.assign(n,0);
    for(int i=1;i<n;i+=1) {
        while(len>0 and pattern[i]!=pattern[len]) len=lps[len-1];
        lps[i]=(pattern[i]==pattern[len])?++len:len;
    }
}
int KMPfind(const string &s,const string &pattern) {
    preKMP(pattern);
    const int sz=s.size(),pz=pattern.size();
    for(int i=0,j=0;i<sz;i+=1) {
        while(j!=0 and s[i]!=pattern[j]) j=lps[j-1];
        if(s[i]==pattern[j]) j++;
        if(j==pz) return i-j+1;
    }
    return -1;
}
    int isPrefixOfWord(string sentence, string searchWord) {
        string s= " "+sentence;
        string t = " "+searchWord; 
        int n = s.size();
        int m = KMPfind(s,t);
        if(m==-1) return -1;
        return 1+count(s.begin(),s.begin()+m,' ');
        }
};
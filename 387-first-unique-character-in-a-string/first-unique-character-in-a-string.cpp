class Solution
{
public:
    int firstUniqChar(string s)
    {
      int n = s.size();
      for (int i = 0; i < n; i++)
      {
        int flag = 1;
        for(int j =0 ;j<n;j++){
            if(i!=j and s[i]==s[j]) {
                flag = 0;
                break;
            }
        }
        if(flag==1){
            return i;
        }
      }
      return -1;
      
    }
};
class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            int n = s.size();
            int kc = 0;
            int flag = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == ' '&&flag) break;
                if (s[i] != ' ')
                {
                    flag = 1;
                    kc++;
                }
            }
            return kc;
        }
};
string ninjaAndStringConversion(int n, string &s)
{
    string res = "";
    for (char ch : s)
    {
        if (islower(ch))
        {
            char uc = (ch - 'a' + 1) % 26 + 'a';
            res += uc;
        }
        else if (isupper(ch))
        {
            char uc = (ch - 'A' + 25) % 26 + 'A';
            res += uc;
        }
        else
        {
            res += ch;
        }
    }
    return res;
}
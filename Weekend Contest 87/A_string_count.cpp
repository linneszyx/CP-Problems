int stringCount(int n, string &s)
{
    int c = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] == '*' and s[i + 1] == '#') or (s[i] == '#' and s[i + 1] == '*'))
            c++;
    }
    return c;
}
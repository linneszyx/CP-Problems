int minimumMax(vector<int> &a)
{
    int l = 0;
    int r = *max_element(a.begin(), a.end());
    int x = INT_MAX;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int mxor = 0;
        for (int num : a)
        {
            mxor = max(mxor, num ^ m);
        }
        if (mxor < r)
            x = mxor;
        if ((m ^ mxor) < m)
            r = m - 1;
        else
            l = m + 1;
    }
    return x;
}
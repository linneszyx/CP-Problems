vector<int> clickbait(int n, vector<int> &a, int q, vector<vector<int>> &queries)
{
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0], r = queries[i][1];
        int count = 0;
        for (int j = l; j <= r; j++)
        {
            if (a[j] == 1)
                count++;
        }
        ans.push_back(count);
    }
    return ans;
}

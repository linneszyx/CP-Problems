class Solution
{
public:
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k)
        {
            k = n - k;
        }
        for (int i = 0; i < k; i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int line = 0; line < numRows; line++)
        {
            vector<int> row;
            for (int i = 0; i <= line; i++)
            {
                row.push_back(binomialCoeff(line, i));
            }
            res.push_back(row);
        }
        return res;
    }
};
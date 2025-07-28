class NumMatrix {
public:
    int r, c;
    vector<vector<int>> g;
    NumMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = r > 0 ? matrix[0].size() : 0;
        g = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i <= r; i += 1) {
            for (int j = 1; j <= c; j += 1) {
                g[i][j] = matrix[i - 1][j - 1] + g[i - 1][j] + g[i][j - 1] -
                          g[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return g[row2 + 1][col2 + 1] - g[row2 + 1][col1] - g[row1][col2 + 1] +
               g[row1][col1];
    }
};

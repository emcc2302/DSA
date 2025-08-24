class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sr = n, er = -1, sc = m, ec = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    sr = min(sr, i);
                    er = max(er, i);
                    sc = min(sc, j);
                    ec = max(ec, j);
                }
            }
        }

        int h = er - sr + 1;
        int w = ec - sc + 1;
        return h * w;
    }
};
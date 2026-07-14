class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    //we push in the queue {{row,col},time}
    //initially time will be 0 and then inc
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                 int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        // Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return tm;
    }
};
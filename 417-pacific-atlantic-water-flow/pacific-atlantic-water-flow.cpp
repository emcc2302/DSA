class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    
    void bfs(int X, int Y, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        queue<pair<int,int>> q;
        q.push({X,Y});
        vis[X][Y] = true;
        int n = heights.size(), m = heights[0].size();

        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> po(n, vector<bool>(m,false)), ao(n, vector<bool>(m,false));
        vector<vector<int>> res;

        for(int i=0; i<n; i++) {
            bfs(i, 0, heights, po);
            bfs(i, m-1, heights, ao);
        }
        for(int j=0; j<m; j++) {
            bfs(0, j, heights, po);
            bfs(n-1, j, heights, ao);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(po[i][j] && ao[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
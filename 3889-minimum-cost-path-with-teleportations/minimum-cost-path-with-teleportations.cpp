class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;
        const int MAX_VAL = 10000;

        // Group coordinates by grid value
        vector<vector<pair<int, int>>> val_to_coords(MAX_VAL + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                val_to_coords[grid[i][j]].push_back({i, j});
            }
        }

        // dist[t][r][c]: min cost to reach (r, c) using exactly t teleports
        vector<vector<vector<int>>> dist(
            k + 1, vector<vector<int>>(m, vector<int>(n, INF))
        );

        dist[0][0][0] = 0;

        for (int t = 0; t <= k; ++t) {
            // Dijkstra for standard moves at teleport level t
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[t][i][j] != INF) {
                        pq.push({dist[t][i][j], i * n + j});
                    }
                }
            }

            while (!pq.empty()) {
                auto [d, pos] = pq.top();
                pq.pop();

                int r = pos / n;
                int c = pos % n;
                if (d > dist[t][r][c]) continue;

                int dr[2] = {0, 1};
                int dc[2] = {1, 0};

                for (int i = 0; i < 2; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < m && nc < n) {
                        if (dist[t][nr][nc] > d + grid[nr][nc]) {
                            dist[t][nr][nc] = d + grid[nr][nc];
                            pq.push({dist[t][nr][nc], nr * n + nc});
                        }
                    }
                }
            }

            // Teleportation to next layer
            if (t < k) {
                vector<int> min_cost_at_val(MAX_VAL + 1, INF);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        min_cost_at_val[grid[i][j]] =
                            min(min_cost_at_val[grid[i][j]], dist[t][i][j]);
                    }
                }

                vector<int> suffix_min(MAX_VAL + 2, INF);
                for (int v = MAX_VAL; v >= 0; --v) {
                    suffix_min[v] = min(suffix_min[v + 1], min_cost_at_val[v]);
                }

                for (int v = 0; v <= MAX_VAL; ++v) {
                    if (suffix_min[v] == INF) continue;
                    for (auto& [r, c] : val_to_coords[v]) {
                        dist[t + 1][r][c] =
                            min(dist[t + 1][r][c], suffix_min[v]);
                    }
                }
            }
        }

        int ans = INF;
        for (int t = 0; t <= k; ++t) {
            ans = min(ans, dist[t][m - 1][n - 1]);
        }

        return ans >= INF ? -1 : ans;
    }
};
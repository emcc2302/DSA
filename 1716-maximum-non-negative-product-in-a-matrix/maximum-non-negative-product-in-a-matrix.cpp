class Solution {
public:
    int maxProductPath(const std::vector<std::vector<int>>& g) {
        int64_t dp[2][16];

        for (int64_t p = 1; auto [x, v] : g[0] | views::enumerate) {
            dp[0][x] = dp[1][x] = p *= v;
        }

        for (auto& row : g | views::drop(1)) {
            dp[0][0] *= row[0], dp[1][0] *= row[0];

            for (auto [x, v] : row | views::enumerate | views::drop(1)) {
                auto a = min(dp[0][x - 1], dp[0][x]);
                auto b = max(dp[1][x - 1], dp[1][x]);
                dp[v < 0][x] = a * v;
                dp[v >= 0][x] = b * v;
            }
        }

        return max(dp[1][g[0].size() - 1], -1L) % 1'000'000'007;
    }
};
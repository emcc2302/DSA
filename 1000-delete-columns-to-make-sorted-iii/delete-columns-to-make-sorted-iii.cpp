class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int dp[m];
        int ans = 0;
        auto ok = [&](int col1, int col2){
            for(int i = 0; i < n; i ++){
                if(strs[i][col1] > strs[i][col2]){
                    return false;
                }
            }
            return true;
        };
        for(int i = 0; i < m; i ++){
            dp[i] = 1;
            for(int j = 0; j < i; j ++){
                if(ok(j, i)){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return m - ans;
    }
};
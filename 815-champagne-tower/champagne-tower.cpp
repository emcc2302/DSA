class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(query_row+2,0.0);
        dp[0]=poured;
        for(int i=1;i<=query_row;i++){
            for(int j=i;j>=0;j--){
                dp[j+1] += dp[j] = max((dp[j]-1)/2,0.0);
            }
        }
        return min(dp[query_glass],1.0);
    }
};
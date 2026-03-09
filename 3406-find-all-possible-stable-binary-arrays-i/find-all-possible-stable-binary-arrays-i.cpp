class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        static int MOD = 1e9 + 7;
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));

        for (int i = 1; i <= min(zero, limit); i++) {
            dp0[i][0] = 1;
        }   

        for (int j = 1; j <= min(one, limit); j++) {
            dp1[0][j] = 1;
        }

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // dp0[i][j]:
                // Add one more zero to states with (i-1, j),
                // then remove the invalid states where the zero-run becomes > limit
                long long val0 = (long long)dp0[i - 1][j] + dp1[i - 1][j];
                if (i - limit - 1 >= 0) {
                    val0 -= dp1[i - limit - 1][j];
                }
                dp0[i][j] = (val0 % MOD + MOD) % MOD;

                // dp1[i][j]:
                // Add one more one to states with (i, j-1),
                // then remove the invalid states where the one-run becomes > limit
                long long val1 = (long long)dp0[i][j - 1] + dp1[i][j - 1];
                if (j - limit - 1 >= 0) {
                    val1 -= dp0[i][j - limit - 1];
                }
                dp1[i][j] = (val1 % MOD + MOD) % MOD;
            }
            
        }
        return ((long long)dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};
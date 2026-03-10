class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1005][1005][2];

    int solve(int z, int o, int last, int zero, int one, int limit) {
        if (z > zero || o > one) return 0;
        if (z == zero && o == one) return 1;

        if (dp[z][o][last] != -1) return dp[z][o][last];

        long long res = 0;

        if (last == 0) {
            if (o + 1 <= one) {
                res = solve(z, o + 1, 1, zero, one, limit);

                if (o + 1 < one) {
                    res = (res + solve(z, o + 1, 0, zero, one, limit)) % MOD;

                    if (o + limit + 1 <= one)
                        res = (res - solve(z, o + limit + 1, 1, zero, one, limit) + MOD) % MOD;
                }
            }
        } 
        else {
            if (z + 1 <= zero) {
                res = solve(z + 1, o, 0, zero, one, limit);

                if (z + 1 < zero) {
                    res = (res + solve(z + 1, o, 1, zero, one, limit)) % MOD;

                    if (z + limit + 1 <= zero)
                        res = (res - solve(z + limit + 1, o, 0, zero, one, limit) + MOD) % MOD;
                }
            }
        }

        return dp[z][o][last] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long res =
            (1LL * solve(0,0,0,zero,one,limit) +
             solve(0,0,1,zero,one,limit)) % MOD;

        return res;
    }
};
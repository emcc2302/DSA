class Solution {
public:
    // haven't started
    // started 1st
    // started 2nd
    // started 3rd.
    // ended all.
    long long dp[100001][3][2][2];
    vector<int>a;
    int n;
    long long MN = -1e16;
    long long INF = 1e16;
    long long solve(int i , int state , int started, int have) {
        if(state == 3) {
            return 0;
        }
        if(i == n) {
            return MN;
        }
        if(dp[i][state][started][have] != INF) {
            return dp[i][state][started][have];
        }

        long long ans = -9e15;

        if(!started) {
            ans = max(ans,solve(i+1,state,started,0));
            // let's start at this index.
            ans = max(ans,a[i] + solve(i+1,state,1,0));
        }
        if(started) {
            if(state == 0) {

                // let's pick this
                if(a[i] > a[i-1]) {
                    ans = max(ans,a[i] + solve(i+1,state,1,1));
                    // let's move to the next state also.
                    ans = max(ans,a[i] + solve(i+1,state+1,1,0));
                }
            }
            if(state == 1) {
                // let's pick this
                if(a[i] < a[i-1]) {
                    ans = max(ans,a[i] + solve(i+1,state,1,1));
                    // let's mvoe to the next state also
                    ans = max(ans,a[i] + solve(i+1,state+1,1,0));
                }
            }
            if(state == 2) {
                // let's pick this
                if(a[i] > a[i-1]) {
                    ans = max(ans,a[i] + solve(i+1,state,1,1));
                    // lets move to the next state also
                    ans = max(ans,a[i] + solve(i+1,state+1,1,0));
                }
            }
        }
        return dp[i][state][started][have] = ans;
        
    }
    
    long long maxSumTrionic(vector<int>& nums) {
        a = nums;
        n = (int)a.size();
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j < 3 ; j++) {
                for(int k = 0 ; k < 2 ; k++) {
                    for(int m = 0 ; m < 2 ; m++) {
                     dp[i][j][k][m] = INF;
                    }
                }
            }
        }
        return solve(0,0,0,0);
    }
};
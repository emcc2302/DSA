//dp

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,INT_MAX);
//         dp[0]=0;

//         for(int i=0;i<n;i++){
//             for(int j=1;j<=nums[i] && j+i<n;j++){
//                 dp[i+j]=min(dp[i+j],dp[i]+1);
//             }
//         }
//         return dp[n-1];
//     }
// };


//greedy optimal


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps=0;
        int reachMost=0;
        int end=0;


        for(int i=0;i<n-1;i++){
            reachMost=max(reachMost,i+nums[i]);

            if(i==end){
                jumps++;
                end=reachMost;
            }
        }
        return jumps;
    }
};
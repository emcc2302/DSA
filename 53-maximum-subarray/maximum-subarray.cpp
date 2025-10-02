//Brute Force
//This will give you tle
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxSum = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             int currSum = 0;
//             for (int j = i; j < n; j++) {
//                 currSum += nums[j];
//                 maxSum = max(maxSum, currSum);
//             }
//         }
//         return maxSum;
//     }
// };


//Prefix Sum
//This will give you tle also

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n+1, 0);
//         for (int i = 0; i < n; i++) {
//             prefix[i+1] = prefix[i] + nums[i];
//         }
//         int maxSum = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = prefix[j+1] - prefix[i];
//                 maxSum = max(maxSum, sum);
//             }
//         }
//         return maxSum;
//     }
// };


//Divide & Conquer
//This Works
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxCrossingSum(vector<int>& nums, int l, int m, int r) {
//         int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
//         for (int i = m; i >= l; i--) {
//             sum += nums[i];
//             leftSum = max(leftSum, sum);
//         }
//         sum = 0;
//         for (int i = m+1; i <= r; i++) {
//             sum += nums[i];
//             rightSum = max(rightSum, sum);
//         }
//         return leftSum + rightSum;
//     }

//     int maxSubArrayHelper(vector<int>& nums, int l, int r) {
//         if (l == r) return nums[l];
//         int m = (l + r) / 2;
//         return max({maxSubArrayHelper(nums, l, m),
//                     maxSubArrayHelper(nums, m+1, r),
//                     maxCrossingSum(nums, l, m, r)});
//     }

//     int maxSubArray(vector<int>& nums) {
//         return maxSubArrayHelper(nums, 0, nums.size()-1);
//     }
// };


//Dynamic Programming
//This Works Too
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n);
//         dp[0] = nums[0];
//         int maxSum = dp[0];
//         for (int i = 1; i < n; i++) {
//             dp[i] = max(nums[i], dp[i-1] + nums[i]);
//             maxSum = max(maxSum, dp[i]);
//         }
//         return maxSum;
//     }
// };



//Kadane’s Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};


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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCrossingSum(vector<int>& nums, int l, int m, int r) {
        int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
        for (int i = m; i >= l; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        sum = 0;
        for (int i = m+1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return leftSum + rightSum;
    }

    int maxSubArrayHelper(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = (l + r) / 2;
        return max({maxSubArrayHelper(nums, l, m),
                    maxSubArrayHelper(nums, m+1, r),
                    maxCrossingSum(nums, l, m, r)});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }
};

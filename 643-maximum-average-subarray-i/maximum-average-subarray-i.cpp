class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int n = nums.size();

        // Calculate sum of first window
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window
        int left = 0;
        for (int right = k; right < n; right++) {
            sum = sum - nums[left] + nums[right];
            left++;

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};
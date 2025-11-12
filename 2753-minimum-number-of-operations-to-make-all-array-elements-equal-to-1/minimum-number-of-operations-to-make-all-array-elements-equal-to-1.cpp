class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0, overall_g = 0;

        for (int x : nums) {
            if (x == 1) num1++;
            overall_g = gcd(overall_g, x);
        }

        if (num1 > 0) return n - num1;
        if (overall_g > 1) return -1;

        int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            if (g == 1) {
                min_len = 1;
                break; // minimal possible
            }
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        return min_len + n - 2;
    }
};

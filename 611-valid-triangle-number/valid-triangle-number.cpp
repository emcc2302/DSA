class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int x = nums[i] + nums[j];
                int l = j + 1, r = n - 1;

                while (l <= r) {
                    int m = l + (r - l) / 2; // binary search mid

                    if (nums[m] < x) {
                        l = m + 1; // try to extend to the right
                    } else {
                        r = m - 1; // shrink to the left
                    }
                }

                // all indices from j+1 .. r are valid
                count += (r - j);
            }
        }

        return count;
    }
};

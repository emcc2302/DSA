class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        int ans = 0;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};

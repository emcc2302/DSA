class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++){
            if (i <= j && (long long)nums[j] > (long long)nums[i] * k){
                i++;
            }
        }
        return i;
    }
};
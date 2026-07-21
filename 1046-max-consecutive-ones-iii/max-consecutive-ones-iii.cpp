class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;  
        int zero_count = 0; 
        int max_ones = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_count++;
            }

          
            while (zero_count > k) {
                if (nums[start] == 0) {
                    zero_count--;
                }
                start++;
            }

           
            max_ones = max(max_ones, i - start + 1);
        }

        return max_ones;
    }
};

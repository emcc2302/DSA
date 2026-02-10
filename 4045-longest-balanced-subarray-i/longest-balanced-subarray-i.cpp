class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int max_len= 0;

        for(int i =0;i<nums.size();i++){
            unordered_map<int, int> mp;
            int odd =0;
            int even =0;
            for(int j = i; j< nums.size();j++){
                if(mp[nums[j]] == 0)
                    {
                        if(nums[j]%2==0) even++;
                        else odd++;
                    }
                mp[nums[j]]++;
                if(even == odd) max_len = max(max_len, j-i+1);
                    
            }
            
        }
        return max_len;
    }
};
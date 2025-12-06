class Solution {
    const int MOD = 1000000007;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        
        multiset<int> currNums;
        vector<int> ways(n + 1);    // number of ways to partition the first i elements
        ways[0] = 1;                // 1 way to partition 0 elements
        
        int l = 0;
        int r = 0;
        long long currWays = 1;     // every valid way ending at r
        while(r < n){
            currNums.insert(nums[r]); 
            while((*currNums.rbegin()) - (*currNums.begin()) > k){ // keeping the max-min <= k
                currNums.erase(currNums.find(nums[l]));
                currWays -= ways[l];
                l++;
                
                if(currWays < 0) currWays += MOD;
            }
            // we have r + 1 elements up to index r.
            ways[r + 1] = currWays; 
            currWays += ways[r + 1]; //all the ways are 

            ways[r + 1] %= MOD; // keeping mods in check
            currWays %= MOD;
           
            r++;                
        }
        return ways[n];
    }
};
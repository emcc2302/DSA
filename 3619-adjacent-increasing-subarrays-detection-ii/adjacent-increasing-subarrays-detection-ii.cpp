#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxK = 0, prev = 0, curr = 1;        
        // single pass - track current and previous increasing run lengths
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                // when run ends, check the max k from prev and curr runs
                maxK = max({maxK, curr / 2, min(prev, curr)});
                prev = curr;
                curr = 1;
            }
        }        
        // don't forget to check the last run
        maxK = max({maxK, curr / 2, min(prev, curr)});        
        return maxK;
    }
};
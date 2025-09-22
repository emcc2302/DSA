#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> res;

        for (int num : nums) {
            res[num]++;
        }

        int x = 0; 
        for (auto &a : res) {
            x = max(x, a.second);
        }

        int count = 0; 
        for (auto &b : res) {
            if (b.second == x) {
                count += b.second; 
            }
        }

        return count;
    }
};

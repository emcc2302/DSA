#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> res;

        // Count frequencies
        for (int num : nums) {
            res[num]++;
        }

        int x = 0; // max frequency
        for (auto &a : res) {
            x = max(x, a.second);
        }

        int count = 0; // count how many elements have freq == x
        for (auto &b : res) {
            if (b.second == x) {
                count += b.second; // add the occurrences
            }
        }

        return count;
    }
};

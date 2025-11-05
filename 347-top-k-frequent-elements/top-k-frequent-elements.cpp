#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        priority_queue<pair<int,int>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }
        vector<int> res;
        while (k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

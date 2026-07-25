class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> first, second;

        for (int num : s1) {
            if (!s2.count(num))
                first.push_back(num);
        }

        for (int num : s2) {
            if (!s1.count(num))
                second.push_back(num);
        }

        return {first, second};
    }
};
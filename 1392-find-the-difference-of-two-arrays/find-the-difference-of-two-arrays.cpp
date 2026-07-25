class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;

        for(int num : nums1){
            mp1[num]++;
        }
        for(int num : nums2){
            mp2[num]++;
        }

        vector<int> first;
        vector<int> second;

        for(auto it : mp1){
            if(mp2.find(it.first) == mp2.end()){
                first.push_back(it.first);
            }
        }
        for(auto it : mp2){
            if(mp1.find(it.first) == mp1.end()){
                second.push_back(it.first);
            }
        }
        return {first, second};
    }
};
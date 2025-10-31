class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = 1; i<nums.size(); i++){
             if(nums[i]==nums[i-1]) ans.push_back(nums[i]);
        }
        return ans;
    }
};




// class Solution {
// public:
//     vector<int> getSneakyNumbers(vector<int>& nums) {
//         vector<int> ans;
//         unordered_map<int,int> mp;
//         for(int i: nums){
//             if(mp[i] == 1){
//                 ans.push_back(i);
//             }
//             mp[i]++;
//         }
//         return ans;
//     }
// };
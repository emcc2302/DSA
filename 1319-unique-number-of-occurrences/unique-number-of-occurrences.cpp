class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int num : arr){
            mp[num]++;
        }   

        unordered_set<int>count;

        for(auto it : mp){
            if(count.find(it.second) != count.end()){
                return false;
            }
            count.insert(it.second);
        }
        return true;
    }
};
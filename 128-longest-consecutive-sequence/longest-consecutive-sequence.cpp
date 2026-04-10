class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>s(nums.begin(),nums.end());

        for(int num :s){
            if(s.find(num-1)==s.end()){
                int current = num;
                int count = 1;
            
            while(s.find(current+1)!=s.end()){
                current++;
                count++;
            }
            longest = max(longest, count);
            }
        }
        return longest;
    }
};
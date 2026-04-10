class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>s(nums.begin(),nums.end());

        for(int num :s){
            if(s.find(num-1)==s.end()){//num will be the first or current  number if num-1 isn't exist
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
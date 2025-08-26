class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int x=0;
        for(auto i:nums){
            x=gcd(i,x);
            if(x==1) return true;
        }
        return false;
    }
};
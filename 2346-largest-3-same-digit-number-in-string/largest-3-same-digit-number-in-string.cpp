class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i = 2; i<n; i++){
            if(num[i-2]==num[i] && num[i-1] == num[i]){
                ans = max(ans , num.substr(i-2, i-(i-2)+1));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num: nums){
            int sum = 0, cnt = 0;
            for(int i = 1; i*i <= num; i++){
                if(num%i==0){
                    if (i * i == num) {
                        cnt += 1;
                        sum += i;
                    } else {
                        cnt += 2;
                        sum += i + (num / i);
                    }
                }
                if (cnt > 4) break;
            }
            ans += (cnt==4? sum : 0);
        }
        return ans;
    }
};
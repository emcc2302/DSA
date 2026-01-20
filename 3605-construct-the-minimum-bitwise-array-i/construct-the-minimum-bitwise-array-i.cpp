class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> Ans(N, -1);

        for (int i = 0; i < N; i++) {
            if (nums[i] == 2) continue;

            int n = nums[i];
            int pos = 0;

            // scan from right to left while bit is 1
            while (n > 0 && ((n >> pos) & 1) == 1) {
                pos++;
            }

            // all bits are 1 → remove MSB
            if ((1 << pos) > n) {
                int highestBit = 31 - __builtin_clz(n);
                n = n & ~(1 << highestBit);
            }
            // found a zero → clear the previous bit
            else {
                n = n & ~(1 << (pos - 1));
            }

            Ans[i] = n;
        }

        return Ans;
    }
};
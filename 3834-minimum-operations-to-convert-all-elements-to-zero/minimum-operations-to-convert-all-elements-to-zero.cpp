class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack(nums.size() + 1, 0);
        int top = 0, ans = 0;
        for (int num : nums) {
            while (stack[top] > num) {
                top--;
                ans++;
            }
            if (stack[top] != num)
                stack[++top] = num;
        }
        return ans + top;
    }
};
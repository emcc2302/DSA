class Solution {
public:
    bool isPowerOfFour(int n) {
        int x = 0;
        while (pow(4, x) <= n) {
            if (n == pow(4, x)) {
                return true;
            }
            x++;
        }
        return false;
    }
};
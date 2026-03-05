class Solution {
public:
    int minOperations(string s) {
        int n, c = 0, j = 0;
        for(n = 0; n < s.size(); n++, j ^= 1) {
            if(s[n] - '0' == j) c++;
        }
        return min(c, n - c);
    }
};
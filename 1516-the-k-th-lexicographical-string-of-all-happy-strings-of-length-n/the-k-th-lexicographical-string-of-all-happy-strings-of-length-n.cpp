class Solution {
public:
   string getHappyString(int n, int k) {
    string chars = "abc";
    int count = 1 << (n - 1);
    if (k > 3 * count) return "";
    
    string result;
    k--;
    result += chars[k / count];
    k %= count;
    
    while (--n) {
        count >>= 1;
        for (char ch : chars) {
            if (ch != result.back()) {
                if (k < count) {
                    result += ch;
                    break;
                }
                k -= count;
            }
        }
    }
    return result;
}
};
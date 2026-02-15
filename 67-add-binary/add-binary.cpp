class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int total = carry;
            if (i >= 0) total += a[i--] - '0';
            if (j >= 0) total += b[j--] - '0';
            result += (total % 2) + '0';
            carry = total / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
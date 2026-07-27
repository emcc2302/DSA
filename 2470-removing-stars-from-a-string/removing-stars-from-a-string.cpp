class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '*') {
                st.pop();      // Remove previous character
            } else {
                st.push(ch);   // Store normal character
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
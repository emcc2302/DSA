class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {

            while (!st.empty() && st.top() > 0 && ast < 0 &&
                   st.top() < abs(ast)) {
                st.pop();
            }

            if (!st.empty() && st.top() > 0 && ast < 0) {

                if (st.top() == abs(ast)) {
                    st.pop();           // both destroyed
                }
                // else st.top() > abs(ast)
                // current asteroid destroyed

            } else {
                st.push(ast);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
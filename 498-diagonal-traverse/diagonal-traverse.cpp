class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans(n * m);
        int idx = 0, flag = 0;

        for (int row = 0; row < n; row++) {
            vector<int> list;
            int i = row, j = 0;
            if (flag % 2 == 0) {
                while (i >= 0 && j < m) {
                    ans[idx++] = mat[i--][j++];
                }
            } else {
                while (i >= 0 && j < m) {
                    list.push_back(mat[i--][j++]);
                }
                for (int x = list.size() - 1; x >= 0; x--) {
                    ans[idx++] = list[x];
                }
            }
            flag++;
        }

        for (int col = 1; col < m; col++) {
            vector<int> list;
            int i = n - 1, j = col;
            if (flag % 2 == 0) {
                while (i >= 0 && j < m) {
                    ans[idx++] = mat[i--][j++];
                }
            } else {
                while (i >= 0 && j < m) {
                    list.push_back(mat[i--][j++]);
                }
                for (int x = list.size() - 1; x >= 0; x--) {
                    ans[idx++] = list[x];
                }
            }
            flag++;
        }

        return ans;
    }
};
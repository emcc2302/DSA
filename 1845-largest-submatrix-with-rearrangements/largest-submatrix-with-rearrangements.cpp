class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) 
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto& row : matrix) {

            for (int j = 0; j < n; j++)
                heights[j] = row[j] ? heights[j] + 1 : 0;

            vector<int> sortedH = heights;
            sort(sortedH.begin(), sortedH.end(), greater<int>());

            for (int j = 0; j < n; j++)
                maxArea = max(maxArea, sortedH[j] * (j + 1));
        }

        return maxArea;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagonals;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                diagonals[r - c].push_back(grid[r][c]);
            }
        }

        for (auto& [key, vec] : diagonals) {
            if (key >= 0) 
                sort(vec.rbegin(), vec.rend());
            else 
                sort(vec.begin(), vec.end());
        }

        unordered_map<int, int> index;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int k = r - c;
                grid[r][c] = diagonals[k][index[k]++];
            }
        }

        return grid;
    }
};

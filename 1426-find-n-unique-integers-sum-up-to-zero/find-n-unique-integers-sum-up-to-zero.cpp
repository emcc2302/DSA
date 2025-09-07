class Solution {
public:
    vector<int> sumZero(int n) {
      vector<int> result;
        
        // If n is even, just take pairs like -1, 1, -2, 2, ...
        for(int i = 1; i <= n/2; i++) {
            result.push_back(-i);
            result.push_back(i);
        }
        
        // If n is odd, add 0 in the middle
        if(n % 2 == 1) {
            result.push_back(0);
        }
        
        return result;
    }
};
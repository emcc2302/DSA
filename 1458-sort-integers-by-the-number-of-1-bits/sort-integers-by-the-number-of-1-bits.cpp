class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [](int a, int b) {
            
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            
            if (bitsA != bitsB)
                return bitsA < bitsB;
            
            return a < b;
        });
        
        return arr;
    }
};
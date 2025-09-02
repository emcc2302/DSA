#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> wanted(friends.begin(), friends.end());
        vector<int> res;
        for (int x : order)
            if (wanted.count(x)) res.push_back(x);
        return res;
    }
};

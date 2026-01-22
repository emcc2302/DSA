class Solution {
public:
    bool is_nondecreasing(const vector<int>& a) {
        for (size_t i = 1; i < a.size(); ++i) {
            if (a[i] < a[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& arr) {
        int cnt = 0;
        if (is_nondecreasing(arr)) return 0;

        while (arr.size() > 1 && !is_nondecreasing(arr)) {
            long long min_sum = LLONG_MAX;
            size_t idx = 0;

            for (size_t i = 0; i + 1 < arr.size(); ++i) {
                long long s = (long long)arr[i] + arr[i+1];
                if (s < min_sum) {
                    min_sum = s;
                    idx = i;   // leftmost pair
                }
            }

            arr[idx] = arr[idx] + arr[idx+1];
            arr.erase(arr.begin() + idx + 1);
            cnt++;
        }
        return cnt;
    }
};

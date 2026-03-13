class Solution {
public:
    bool canFinish(long long T, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (int w : workerTimes) {
            long double val = (2.0L * T) / w;
            long long x = (long long)((sqrtl(1.0L + 4.0L * 2.0L * T / w) - 1) / 2);

            // safer formula:
            x = (long long)((sqrtl(1.0L + 8.0L * T / w) - 1) / 2);

            // adjust if needed
            while ((long long)w * x * (x + 1) / 2 > T) x--;
            while ((long long)w * (x + 1) * (x + 2) / 2 <= T) x++;

            total += x;
            if (total >= mountainHeight) return true;
        }

        return total >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1LL * (*min_element(workerTimes.begin(), workerTimes.end())) 
                         * mountainHeight * (mountainHeight + 1) / 2;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
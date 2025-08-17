#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;
        deque<double> window;      
        double windowSum = 1.0;   
        double ans = 0.0;

        window.push_back(1.0);

        for (int i = 1; i <= n; ++i) {
            double dpi = windowSum / maxPts;  

            if (i < k) {
                windowSum += dpi;
            } else {
                ans += dpi;
            }
            window.push_back(dpi);
            if ((int)window.size() > maxPts) {
                windowSum -= window.front();
                window.pop_front();
            }
        }

        return ans;
    }
};

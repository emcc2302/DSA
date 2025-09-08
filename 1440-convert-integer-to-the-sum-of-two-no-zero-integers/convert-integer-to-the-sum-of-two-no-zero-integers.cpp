class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;

        for (int a = 1; a < n; a++) {
            int b = n - a;

            // check if 'a' or 'b' contains zero
            int x = a, y = b;
            bool ok = true;

            while (x > 0) {
                if (x % 10 == 0) { ok = false; break; }
                x /= 10;
            }
            while (ok && y > 0) {
                if (y % 10 == 0) { ok = false; break; }
                y /= 10;
            }

            if (ok) {
                res.push_back(a);
                res.push_back(b);
                break;
            }
        }

        return res;
    }
};

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        int blocks = (n + 63) / 64;
        vector<vector<unsigned long long>> masks(m+1, vector<unsigned long long>(blocks,0));
        
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                int idx = (lang-1)/64, bit = (lang-1)%64;
                masks[i+1][idx] |= (1ULL << bit);
            }
        }

        unordered_set<int> candidates;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int b = 0; b < blocks; b++) {
                if (masks[u][b] & masks[v][b]) { canTalk = true; break; }
            }
            if (!canTalk) { candidates.insert(u); candidates.insert(v); }
        }
        if (candidates.empty()) return 0;

        vector<int> count(n+1,0);
        for (int u : candidates) {
            for (int lang = 1; lang <= n; lang++) {
                int idx = (lang-1)/64, bit = (lang-1)%64;
                if (masks[u][idx] & (1ULL<<bit)) count[lang]++;
            }
        }

        int maxOverlap = *max_element(count.begin(), count.end());
        return (int)candidates.size() - maxOverlap;
    }
};
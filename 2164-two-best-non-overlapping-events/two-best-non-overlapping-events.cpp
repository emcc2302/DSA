class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //compress the values:
        set<int> S;
        for(auto event : events){
            S.insert(event[0]);
            S.insert(event[1]);
        }
        unordered_map<int, int> new_val;
        int M = 1;
        for(auto x : S){
            new_val[x] = M;
            M += 1;
        }
        for(auto &event : events){
            event[0] = new_val[event[0]];
            event[1] = new_val[event[1]];
        }
        //------end of compression---------

        //prefix calculations
        vector<int> MAX_ENDING_AT(M + 1, 0);
        for(auto event : events){
            int r   = event[1];
            int val = event[2];
            MAX_ENDING_AT[r] = max(MAX_ENDING_AT[r], val);
        }
        vector<int> PREF_MAX(M + 1, 0);
        for(int i = 1; i < M; i ++){
            PREF_MAX[i] = max(PREF_MAX[i - 1], MAX_ENDING_AT[i]);
        }

        //suffix calculations:
        vector<int> MAX_STARTING_AT(M + 1, 0);
        for(auto event : events){
            int l   = event[0];
            int val = event[2];
            MAX_STARTING_AT[l] = max(MAX_STARTING_AT[l], val);
        }
        vector<int> SUFF_MAX(M + 1, 0);
        for(int i = M - 1; i >= 0; i --){
            SUFF_MAX[i] = max(SUFF_MAX[i + 1], MAX_STARTING_AT[i]);
        }


        int ans = 0;
        for(int p = 0; p < M; p ++){
            ans = max(ans, PREF_MAX[p] + SUFF_MAX[p + 1]);
        }

        return ans;
    }
};
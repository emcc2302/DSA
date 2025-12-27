using ll = long long;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> ready;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> rooms;

        for (int r = 0; r < n; r++){
            ready.push(r);
        }

        vector<int> res(n, 0);

        for (auto& mt : meetings){
            ll s = mt[0];
            ll e = mt[1];

            while (!rooms.empty() && rooms.top().first <= s){
                int r = rooms.top().second;
                rooms.pop();
                ready.push(r);
            }

            int r;
            if (!ready.empty()){
                r = ready.top();
                ready.pop();
                rooms.push({e, r});
            } else {
                auto top = rooms.top();
                rooms.pop();
                r = top.second;
                ll t = top.first;
                rooms.push({t + (e - s), r});
            }

            res[r]++;
        }

        return distance(res.begin(), max_element(res.begin(), res.end()));
    }
};
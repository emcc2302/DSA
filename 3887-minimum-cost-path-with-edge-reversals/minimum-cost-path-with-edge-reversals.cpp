class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> res(n + 1, INT_MAX);

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});       // normal edge
            adj[v].push_back({u, w * 2});   // reversed edge using switch
        }

        // Min-heap for Dijkstra
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        res[0] = 0;

        while (!pq.empty()) {
            auto [dist, currNode] = pq.top();
            pq.pop();

            for (auto &edge : adj[currNode]) {
                int nextNode = edge.first;
                int cost = edge.second;

                if (dist + cost < res[nextNode]) {
                    res[nextNode] = dist + cost;
                    pq.push({res[nextNode], nextNode});
                }
            }
        }

        return res[n - 1] == INT_MAX ? -1 : res[n - 1];
    }
};
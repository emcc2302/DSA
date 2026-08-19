class Solution {
public:

    int dfs(int city, vector<vector<pair<int,int>>>& graph,
            vector<bool>& visited) {

        visited[city] = true;

        int changes = 0;

        for (auto [nextCity, cost] : graph[city]) {

            if (!visited[nextCity]) {

                changes += cost;

                changes += dfs(nextCity, graph, visited);
            }
        }

        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto connection : connections) {

            int a = connection[0];
            int b = connection[1];

            graph[a].push_back({b, 1});
            graph[b].push_back({a, 0});
        }

        vector<bool> visited(n, false);

        return dfs(0, graph, visited);
    }
};
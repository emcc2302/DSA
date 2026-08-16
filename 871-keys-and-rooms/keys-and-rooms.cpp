class Solution {
public:

    void dfs(int room,vector<vector<int>>& rooms,vector<bool>& visited){
        visited[room]=true;

        for(int keys : rooms[room]){
            if(!visited[keys]){
                dfs(keys, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
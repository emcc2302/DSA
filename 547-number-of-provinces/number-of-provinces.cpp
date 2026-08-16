class Solution {

void dfs(int city,vector<vector<int>>& isConnected,vector<bool>& visited){
    visited[city]=true;
    //i means nextCity
    for(int i=0;i<isConnected.size();i++){
        if(isConnected[city][i]==1 && !visited[i]){
            dfs(i, isConnected, visited);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);


        int provinces = 0;

        for (int city = 0; city < n; city++) {

            if (!visited[city]) {

                provinces++;

                dfs(city, isConnected, visited);
            }
        }

        return provinces;
    }
};
class Solution {
private:
    void dfs(int start, vector<vector<int>>& isConnected,
             vector<bool> &visited) {
        visited[start] = 1;
        for (int i = 0; i < isConnected[start].size(); i++) {
            if (!visited[i] && isConnected[start][i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<bool> visited(n, 0);
        int start = 0;
        int cnt(0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
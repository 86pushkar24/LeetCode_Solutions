class Solution {
private:
    void bfs(int row, int col,vector<vector<bool>> &visited,vector<vector<char>> &grid,int n,int m){
        queue<pair<int,int>> q;
        q.push({row,col});
        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = row + deltaRow[i];
                int nCol = col + deltaCol[i];
                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol]=='1'){
                    visited[nRow][nCol] = true;
                    q.push({nRow,nCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m,false));
        int ans(0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j,visited,grid,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
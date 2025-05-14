class Solution {
private:
    // void bfs(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, vector<vector<bool>>& visited) {
    //     queue<pair<int, int>> q;
    //     q.push({sr, sc});
    //     visited[sr][sc] = true;
    //     int initialColor = image[sr][sc];
    //     vector<int> dr = {-1, 0, 1, 0};
    //     vector<int> dc = {0, 1, 0, -1};
    //     while (!q.empty()) {
    //         int r = q.front().first;
    //         int c = q.front().second;
    //         q.pop();
    //         for (int i = 0; i < 4; i++) {
    //             int nr = r + dr[i];
    //             int nc = c + dc[i];
    //             if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && image[nr][nc] == initialColor) {
    //                 visited[nr][nc] = true;
    //                 image[nr][nc] = color;
    //                 q.push({nr, nc});
    //             }
    //         }
    //     }
    // }
    void dfs(vector<vector<int>>& ans, int sr, int sc, int color,int initialColor,int n,int m, int delRow[],int delCol[]){
        //  if (sr < 0 || sr >= n || sc < 0 || sc >= m || ans[sr][sc] != initialColor) {
        //     return; // Base case: out of bounds or not the same color
        // }
        ans[sr][sc]=color;
        for(int i = 0; i < 4;i++){
            int nr = sr + delRow[i];
            int nc = sc + delCol[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && ans[nr][nc] == initialColor){
                dfs(ans,nr,nc,color,initialColor,n,m,delRow,delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        // if (image[sr][sc] != color) {
        //     bfs(image, sr, sc, color, n, m, visited);
        //     image[sr][sc] = color;
        // }
        // return image;
        vector<vector<int>> ans = image;
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};
        int initialColor = ans[sr][sc];
        if(!(ans[sr][sc] == color)){
            dfs(ans,sr,sc,color,initialColor,n,m,delRow,delCol);
        }
        return ans;
    }
};
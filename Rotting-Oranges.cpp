class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> inp = grid;
        queue<pair<int, int>> rotten_q;
        int fresh_count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (inp[i][j] == 2) {
                    rotten_q.push({i, j});
                } 
                else if (inp[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) {
            return 0;
        }

        int time = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!rotten_q.empty() && fresh_count > 0) {
            int sz = rotten_q.size(); 
            for (int k = 0; k < sz; k++) {
                pair<int, int> curr = rotten_q.front();
                rotten_q.pop();
                int r = curr.first;
                int c = curr.second;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && inp[nr][nc] == 1) {
                        inp[nr][nc] = 2;
                        rotten_q.push({nr, nc});
                        fresh_count--;
                    }
                }
            }
            time++;
        }
        return (fresh_count == 0) ? time : -1;
    }
};
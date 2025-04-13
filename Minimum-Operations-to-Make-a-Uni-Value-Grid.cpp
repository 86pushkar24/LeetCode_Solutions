class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;  // don't pre-size it
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(grid[i][j]);
            }
        }
        // sort(v.begin(), v.end()); O(nlogn)
        nth_element(v.begin(), v.begin() + (v.size() / 2), v.end()); // O(n)
        int median = v[v.size() / 2];
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            int diff = abs(v[i] - median);
            if (diff % x != 0) return -1; // not possible to equalize
            cnt += diff / x;
        }
        return cnt;
    }
};

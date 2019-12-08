https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    int dirx[4] = {0, 0, -1, 1};
    int diry[4] = {1, -1, 0, 0};
    bool is_valid(vector<vector<int>>& b, int i, int j){
        int n = b.size(), m = b[0].size();
        return i >= 0 && i < n && j >= 0 && j < m && b[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int n = grid.size(), m = grid[0].size(), fresh = 0;
        vector<vector<int>> b(grid.begin(), grid.end());
        queue<pair<int, int>> q;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(b[i][j] == 1){
                    fresh++;
                }else if(b[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if(fresh == 0) return 0;

        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int nexti = p.first + dirx[i];
                    int nextj = p.second + diry[i];
                    if(is_valid(b, nexti, nextj)){
                        q.push({nexti, nextj});
                        b[nexti][nextj] = 2;
                        fresh--;
                    }
                }
            }
            if(!q.empty()) step++;
        }
        return fresh == 0 ? step : -1;
    }
};

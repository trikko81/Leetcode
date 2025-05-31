class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int fresh = 0;
        int time = 0;

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                } 
                if(grid[r][c] == 2) {
                    que.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(fresh > 0 && !que.empty()) {
            int n = que.size();
            for(int i = 0; i < n; i++) {
                auto curr = que.front();
                que.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        que.push({row, col});
                        fresh--;
                    }   
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};

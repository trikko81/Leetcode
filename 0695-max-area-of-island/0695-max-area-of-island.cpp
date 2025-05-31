class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size(), false));

        for (int c = 0; c < grid.size(); c++) {
            for (int r = 0; r < grid[0].size(); r++) {
                if (grid[c][r] == 1 && !explored[c][r]) { 
                    int area = bfs(c, r, grid, explored);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int bfs(int c, int r, vector<vector<int>>& grid, vector<vector<bool>>& explored) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> que;
        que.push({c, r});
        explored[c][r] = true;

        int area = 0;

        while (!que.empty()) {
            pair<int, int> front = que.front();
            int currC = front.first;
            int currR = front.second;
            que.pop();

            area++;

            for (const pair<int, int>& dir : directions) {
                int dc = dir.first;
                int dr = dir.second;
                int newC = currC + dc;
                int newR = currR + dr;

                if (newC >= 0 && newC < grid.size() && newR >= 0 && newR < grid[0].size()
                    && grid[newC][newR] == 1 && !explored[newC][newR]) {  
                    explored[newC][newR] = true;
                    que.push({newC, newR});
                }
            }
        }

        return area;
    }
};

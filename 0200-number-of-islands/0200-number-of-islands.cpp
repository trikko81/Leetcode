class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //create island count = 0
        int island = 0;
        //create explored grid = to the dimentions of grid but hold all falses
        vector<vector<bool>> explored(grid.size(), vector<bool>(grid[0].size(), false));
        //go through grid in a for loop
        for(int c = 0; c < grid.size(); c++){
            for(int r = 0; r < grid[0].size(); r++){
            //check if r,c in explored grid is equal to false and is a land mass
                if(explored[c][r] == false && grid[c][r] == '1'){
                    //run the bfs helper
                    bfs(c,r, grid, explored);
                    //increment island count
                    island++;
                }
            //explored grid r,c now becomes true
            explored[c][r] == true;
            }
        }
        
        //return island count
        return island;
    }
    //bfs helper function to look for land masses takes a grid coord 
    void bfs(int c, int r,vector<vector<char>>& grid, vector<vector<bool>>& explored){
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> que;
        que.push({c, r});
        explored[c][r] = true;
        
        while(!que.empty()){
            //explored[currC][currR] = true;
            //auto [curC, curR] = que.front();
            std::pair<int, int> front = que.front();
            int currC = front.first;
            int currR = front.second;
            que.pop();


            for (const std::pair<int, int>& dir : directions) {
                int dc = dir.first;
                int dr = dir.second; 
                int newC = currC + dc;
                int newR = currR + dr;
                if (newC >= 0 && newC < grid.size() && newR >= 0 && newR < grid[0].size()
                && grid[newC][newR] == '1' && !explored[newC][newR]) {
                    explored[newC][newR] = true;
                    que.push({newC, newR});  
                }

            }
        }

    }

    
};

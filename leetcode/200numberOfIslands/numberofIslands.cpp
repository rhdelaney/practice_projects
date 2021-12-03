class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //mark nodes as "seen"
        //dfs
        //need a counter
        int islands = 0;
        //loop through list
        for (int i = 0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                //values can be 0 = water, 1 = land, and 2 if seen
                if (grid[i][j] == '1') {
                    //we found an island
                    //now let's see the nodes/land attached to it
                    DFS(grid,i,j);
                    ++islands;
                }
            }
        }
        return islands;
    }
    void DFS(vector<vector<char>>& grid, int row, int col) {
       if (row<0 || row >= grid.size() || col<0 || col >= grid[0].size()) {
           //out of the grid we return
           return;
       }
       if (grid[row][col] == '2' || grid[row][col] == '0') {
           //if it's seen or water we return
           return;
       }
        //mark as seen if '1'
        grid[row][col] = '2';

        //more dfs recursively
        DFS(grid, row+1, col);
        DFS(grid, row, col-1);
        DFS(grid, row-1, col);
        DFS(grid, row, col+1);
    }
};

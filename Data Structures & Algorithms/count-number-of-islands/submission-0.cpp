class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int column){
        int row_count = grid.size();
        int column_count = grid[0].size();

        if (row<0 || column<0 || column>=column_count || row>=row_count || grid[row][column]=='0'){
            return;
        }

        grid[row][column]='0';

        dfs(grid, row+1, column);
        dfs(grid, row-1,column);
        dfs(grid, row, column+1);
        dfs(grid, row, column-1);


    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int count=0;
        for (int r=0;r<grid.size();++r){
            for(int c=0;c<grid[0].size();++c){
                if (grid[r][c]=='1'){
                    count++;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
        
    }
};

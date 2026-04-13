class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited, int prevHeight) {
        int rows = heights.size();
        int cols = heights[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;

        dfs(r + 1, c, heights, visited, heights[r][c]);
        dfs(r - 1, c, heights, visited, heights[r][c]);
        dfs(r, c + 1, heights, visited, heights[r][c]);
        dfs(r, c - 1, heights, visited, heights[r][c]);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific, heights[r][0]);
            dfs(r, cols - 1, heights, atlantic, heights[r][cols - 1]);
        }

        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific, heights[0][c]);
            dfs(rows - 1, c, heights, atlantic, heights[rows - 1][c]);
        }

        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};

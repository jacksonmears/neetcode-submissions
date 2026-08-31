class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        row_count = grid.size();
        col_count = grid[0].size();
        seen.resize(row_count * col_count);

        for (size_t row = 0; row < row_count; ++row)
        {
            for (size_t col = 0; col < col_count; ++col)
            {
                if (grid[row][col] && !seen[row*col_count + col]) 
                {
                    dfs(grid, row, col);
                    cur = 0;
                }
            }
        }
        
        return mx;
    }

private:
    int cur = 0, mx = 0;

    int col_count, row_count;
    vector<int> seen;
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,-1},{0,1}};

    bool in_bounds(int row, int col)
    {
        return (row >= 0 && row < row_count && col >= 0 && col < col_count);
    }


    void dfs(vector<vector<int>>& grid, int row, int col)
    {
        cur += 1;

        seen[row*col_count + col] = 1;

        mx = max(mx, cur);
        
        for (pair<int,int> dir : directions)
        {
            int r   = row + dir.first;
            int c   = col + dir.second;

            if (!in_bounds(r,c) || seen[r*col_count + c] || grid[r][c] == 0) continue;

            dfs(grid, r, c);
        }
    }
};



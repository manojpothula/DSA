class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& vis)
    {
        vis[r][c] = 1;

        queue<pair<int,int>> q;
        q.push({r, c});

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == '1' &&
                   !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return cnt;
    }
};
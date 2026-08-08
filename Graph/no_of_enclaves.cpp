class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        int drow[]={0,0,-1,1};
        int dcol[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow >=0 && nrow<n &&ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j])
                    dfs(i,j,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                   count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                   q.push({i,j});
    
                }
                else
                {
                    dis[i][j]=-1;
                }
            }
        }
            while(!q.empty())
            {
               int r=q.front().first;
               int c=q.front().second;
               q.pop();
               int drow[]={0,0,1,-1};
               int dcol[]={1,-1,0,0};
               for(int i=0;i<4;i++)
               {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dis[nrow][ncol]==-1)
                {
                    dis[nrow][ncol]=   dis[r][c]+1;
                    q.push({nrow,ncol});
                }
               
               }

            }
        
        return dis;
    }
};
class Solution {
  public:
    void d(int node,vector<vector<int>>& adj,vector<int>&ls,int vis[])
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                d(it,adj,ls,vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ls;
        int n=adj.size();
        int vis[n]={0};
        vis[0]=1;
        int start=0;
        d(start,adj,ls,vis);
        return ls;
        }
};
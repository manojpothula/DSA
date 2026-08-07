class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
               dfs(it,adj,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<vector<int>> adj(n);

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        
        dfs(source,adj,vis);
        return vis[destination];
    }
};
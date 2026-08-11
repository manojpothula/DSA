class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,int &extraedges)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
               dfs(it,vis,adj,extraedges);
            else
              extraedges++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int extraedges=0;
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i,vis,adj,extraedges);
            }
        }
        extraedges=extraedges/2;
        if(extraedges>=components-1)
           return components-1;
        return -1;

    }
};
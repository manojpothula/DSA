class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, stack<int>& st)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges)
    {
        vector<int> ans;
        vector<int> vis(V, 0);
        stack<int> st;

        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
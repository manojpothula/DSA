class Solution {
  private:
    void toposort(int node,vector<pair<int,int>>adj[],vector<int>& vis,stack<int>& st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it.first])
              toposort(it.first,adj,vis,st);
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
               toposort(i,adj,vis,st);
        }
        
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if(dist[node]!=INT_MAX && dist[node]+wt < dist[v])
                {
                    dist[v]=dist[node]+wt;
                }
            }
        }
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++)
        {
            if(dist[i]!=INT_MAX)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};

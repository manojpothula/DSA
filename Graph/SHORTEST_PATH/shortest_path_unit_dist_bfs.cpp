class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int>adj[V];
        vector<int>dist(V,INT_MAX);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
            if(dist[node] + 1 < dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
            }
        }
        if(dist[dest]!=INT_MAX)
           return dist[dest];
         return -1;
    }
};

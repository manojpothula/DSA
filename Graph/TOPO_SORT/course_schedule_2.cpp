class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis, stack<int>& st)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(!dfs(it, adj, vis, pathVis, st))
                    return false;
            }
            else if(pathVis[it])
            {
                return false;
            }
        }

        pathVis[node] = 0;
        st.push(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> ans;
        stack<int> st;

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(!dfs(i, adj, vis, pathVis, st))
                    return {};
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
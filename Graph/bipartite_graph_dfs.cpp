class Solution {
private:
    bool check(int start, int parent, vector<vector<int>>& graph, vector<int>& color)
    {
        if(parent == -1)
            color[start] = 0;
        else
            color[start] = !color[parent];

        for(auto it : graph[start])
        {
            if(color[it] == -1)
            {
                if(check(it, start, graph, color) == false)
                    return false;
            }
            else if(color[it] == color[start])
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(check(i, -1, graph, color) == false)
                    return false;
            }
        }

        return true;
    }
};
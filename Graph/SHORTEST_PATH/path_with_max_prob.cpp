class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        // Adjacency list
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        // Maximum probability to reach each node
        vector<double> dist(n, 0.0);

        // {probability, node}
        priority_queue<pair<double, int>> pq;

        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {

            double prob = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (pair<int, double> it : adj[node]) {

                int adjNode = it.first;
                double edgeProb = it.second;

                double newProb = prob * edgeProb;

                if (newProb > dist[adjNode]) {

                    dist[adjNode] = newProb;

                    pq.push({newProb, adjNode});
                }
            }
        }

        return dist[end];
    }
};
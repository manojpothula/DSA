#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin >>n >> m;
vector<vector<int>>adj(n+1,vector<int>(n+1,0));
for(int i=0;i<m;i++)
{
    int u,v,w;
    cin >>u>>v>>w;
    adj[u][v]=w;
    adj[v][u]=w;
}
cout << "Adjacency matrix :" << endl;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cout << adj[i][j] << " ";
    }
    cout << endl;
}
}

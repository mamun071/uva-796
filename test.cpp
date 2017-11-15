#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MX 10010
#define S(n) scanf("%d", &n);

vector<int> adj[MX];
int vis[MX];

vector< pair<int, int> > bridge;
pair<int, int> pii;
int t, dis[MX], low[MX], parent[MX];

void findBridge(int u)
{
    low[u] = dis[u] = ++t;
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            parent[v]=u;
            findBridge(v);
            low[u]=min(low[u], low[v]);
            if(low[v]>dis[u])   //edge(u, v) is bridge
            {
                pii.first=u, pii.second=v;
                if(u>v)
                    swap(pii.first, pii.second); // if sort requires
                bridge.push_back(pii);
            }
        }
        else if(parent[u]!=v)
            low[u]=min(low[u], dis[v]);
    }
    return;
}

int main()
{
    int tc,kk=1,n,u,v,num;
    while(scanf("%d", &n)==1)
    {
        for(int i=0;i<MX;i++)
        {
            vis[i]=0;
            adj[i].clear();
        }
        t=0;
        for(int i=0;i<n;i++)
        {
            S(u);
            scanf(" (%d)",&num);
            for(int j=0;j<num;j++)
            {
                S(v);
                adj[u].push_back(v);
            }
        }

        bridge.clear();
        for(int i=0;i<n;i++)
            if(!vis[i])
                findBridge(i);

        sort(bridge.begin(), bridge.end());
        printf("%d critical links\n",bridge.size());
        for(int i=0;i<bridge.size();i++)
            printf("%d - %d\n",bridge[i].first,bridge[i].second);
        printf("\n");
    }
    return 0;
}

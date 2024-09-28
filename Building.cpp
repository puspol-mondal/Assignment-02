#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_Size[N];

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_Size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;

    int l = dsu_find(parent[node]);
    parent[node] = l;
    return l;
}
void dsu_union(int x, int y)
{
    int leaderA = dsu_find(x);
    int leaderB = dsu_find(y);

    if (group_Size[leaderA] > group_Size[leaderB])
    {

        parent[leaderB] = leaderA;
        group_Size[leaderA] += group_Size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_Size[leaderB] += group_Size[leaderA];
    }
}

bool cmp(Edge a, Edge b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgelist;
    dsu_initialize(n);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back(Edge(u, v, w));
    }
    sort(edgelist.begin(), edgelist.end(), cmp);
    ll ttCost = 0;
    for (Edge ed : edgelist)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        if (leaderA != leaderB)
        {
            dsu_union(leaderA, leaderB);
            ttCost += ed.w;
        }
    }
    int mainL = dsu_find(1);
    bool flg = true;
    for (int i = 0; i < n; i++)
    {
        if (dsu_find(i) != mainL)
        {
            flg = false;
        }
    }
    if (flg)
    {
        cout << ttCost;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
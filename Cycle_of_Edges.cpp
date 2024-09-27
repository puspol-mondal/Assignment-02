#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];
int parent[N];
int cycle = 0;
void dfs(int s)
{
    vis[s] = true;

    for (int child : v[s])
    {
        if (vis[child] == true && child != parent[s])
        {
            cycle++;
        }

        if (!vis[child])
        {
            parent[child] = s;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    dfs(1);
    cout << cycle / 2 << endl;
    return 0;
}
//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 105
#define MOD
#define Task "proA_bonus"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m, d[maxn];
int x, y, z;
vii ke[maxn];
int bf[maxn];
int Dijkstra(int s)
{
    map <pii, int> mp;
    fill(d + 1, d + n + 1, oo);
    d[s] = 0;
    priority_queue <pii> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (d[u] != dw) continue;
        for (pii pr : ke[u])
        {
            int v = pr.F;
            int w = pr.S;
            if (d[v] > dw + w) {
                bf[v] = u;
                d[v] = dw + w;
                pq.push({-d[v], v});
            }
        }
    }
    int res = 0;

    int u = x;
    while (u != s)
    {
        int p = bf[u];
        if (!mp[{min(u, p), max(u, p)}])
            {
                mp[{min(u, p), max(u, p)}] = 1;
                res += d[u]- d[p];
            }
        u = p;
    }

    u = y;
    while (u != s)
    {
        int p = bf[u];
        if (!mp[{min(u, p), max(u, p)}])
            {
                mp[{min(u, p), max(u, p)}] = 1;
                res += d[u]- d[p];
            }
        u = p;
    }

    u = z;
    while (u != s)
    {
        int p = bf[u];
        if (!mp[{min(u, p), max(u, p)}])
            {
                mp[{min(u, p), max(u, p)}] = 1;
                res += d[u]- d[p];
            }
        u = p;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    cin >> x >> y >> z;
    cout << min(Dijkstra(x), min(Dijkstra(y), Dijkstra(z)));
}

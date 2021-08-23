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
#define mp make_pair
#define maxn 105
#define MOD
#define Task "proC_bonus"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
vii ke[maxn];
int H_t, H_m, S_t, S_m;
bool dd[maxn];
int d_t[maxn], d_m[maxn];
bool check_t[maxn], check_m[maxn];
int bf_t[maxn], bf_m[maxn];
int bf[maxn];
int d[maxn];
void dfs_t(int u)
{
    dd[u] = 1;
    for (pii x : ke[u])
    {
        int v = x.F;
        int w = x.S;
        if (d_t[v] + w == d_t[u] && !dd[v])
        {
            check_t[v] = 1;
            dfs_t(v);
        }
    }
}
void ijk_t()
{
    fill(d_t + 1, d_t + n + 1, oo);
    reset(dd, 0);
    d_t[H_t] = 0;
    priority_queue <pii> pq;
    pq.push({0, H_t});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw > d_t[u])
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d_t[v] > dw + w) {
                bf_t[v] = u;
                d_t[v] = dw + w;
                pq.push({-d_t[v], v});
            }
        }
    }
    check_t[S_t] = 1;
    dfs_t(S_t);
}
void dijkstra(int s)
{
    fill(d , d + n + 1, oo);
    d[s] = 0;
    priority_queue <pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw > d[u])
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v] > dw + w) {
                bf[v] = u;
                d[v] = dw + w;
                pq.push({-d[v], v});
            }
        }
    }
}

void dfs_m(int u)
{
    dd[u] = 1;
    for (pii x : ke[u])
    {
        int v = x.F;
        int w = x.S;
        if (d_m[v] + w == d_m[u] && !dd[v])
        {
            check_m[v] = 1;
            dfs_m(v);
        }
    }
}
void ijk_m()
{
    fill(d_m + 1, d_m + n + 1, oo);
    reset(dd, 0);
    d_m[H_m] = 0;
    priority_queue <pii> pq;
    pq.push({0, H_m});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw > d_m[u])
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d_m[v] > dw + w) {
                bf_m[v] = u;
                d_m[v] = dw + w;
                pq.push({-d_m[v], v});
            }
        }
    }
    check_m[S_m] = 1;
    dfs_m(S_m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    cin >> H_t >> S_t;
    cin >> H_m >> S_m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    ijk_t();
    ijk_m();
    int mn = oo;
    int res = 0;
    for (int i = 1; i <= n; i ++)
        if (check_t[i] && check_m[i] && d_t[i] == d_m[i])
            if(d_t[i] < mn) res = i, mn = d_t[i];
    if (!res)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    dijkstra(res);
    vi duong_t;
    vi duong_m;
    int u = S_t;
    while (u != res)
    {
        duong_t.PB(u);
        u = bf[u];
    }
    while (u != H_t)
    {
        duong_t.PB(u);
        u = bf_t[u];
    }
    duong_t.PB(H_t);
    u = S_m;
    while (u != res)
    {
        duong_m.PB(u);
        u = bf[u];
    }
    while (u != H_m)
    {
        duong_m.PB(u);
        u = bf_m[u];
    }
    duong_m.PB(H_m);
    cout << d_t[S_t] << "\n";
    for (int i = sz(duong_t) - 1; i >= 0; i --) cout << duong_t[i] << " ";
    cout << "\n";
    cout << d_m[S_m] << "\n";
    for (int i = sz(duong_m) - 1; i >= 0; i --) cout << duong_m[i] << " ";
    cout << "\n";
    cout << res << "\n";
    cout << mn;
}

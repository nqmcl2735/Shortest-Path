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
#define maxn 100005
#define MOD
#define Task "minpath"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke[maxn];
int n, m, s, t;
int d[maxn];
int bf[maxn];
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    dijkstra(s);
    cout << d[t];
    /*
    int x = t;
    vi ans;
    while (x != s)
    {
        ans.PB(x);
        x = bf[x];
    }
    ans.PB(s);
    fo << sz(ans) << "\n";
    for (int i = sz(ans) - 1; i >= 0; i --)
        fo << ans[i] << " ";
    */
}

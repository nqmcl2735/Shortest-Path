//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo LLONG_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task "TUNNELS"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, s, t;
int m;
struct edg{
    int v;
    int h;
    ll w;
};
vector <edg> ke[maxn];
vi height;
ll d[maxn];
ll Sol(int hi)
{
    fill(d , d + n + 1, oo);
    d[s] = 0;
    priority_queue <pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        ll dw = -pq.top().F;
        pq.pop();
        if (dw > d[u])
            continue;
        for (edg x : ke[u])
        {
            int v = x.v;
            ll w = x.w;
            int h = x.h;
            if (h < hi) continue;
            if (d[v] > dw + w) {
                d[v] = dw + w;
                pq.push({-d[v], v});
            }
        }
    }
    return d[t];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> s >> t >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, h;
        ll w;
        cin >> u >> v >> h >> w;
        ke[u].PB({v, h, w});
        ke[v].PB({u, h, w});
        height.PB(h);
    }
    sort(height.begin(), height.end());
    height.erase(unique( height.begin(), height.end() ), height.end());
    int l = -1;
    int r = sz(height);
    int hi; ll res;
    while(l <= r)
    {
        int mid = (l + r)/2;
        ll g = Sol(height[mid]);
        if (g == oo) r = mid - 1;
        else {
            l = mid + 1;
            hi = height[mid];
            res = g;
        }
    }
    cout << hi << " " << res;
    return 0;
}

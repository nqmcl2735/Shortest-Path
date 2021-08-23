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
#define maxn 20000
#define MOD
#define Task "proB"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
vii ke[maxn];
pii d[maxn];
//int bf[maxn];
void dijkstra1()
{
    for (int i = 1; i <= n; i ++)
        d[i].F = oo;
    d[1].F = 0;
    priority_queue <pii> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw > d[u].F)
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v].F > dw + w) {
                //bf[v] = u;
                d[v].F = dw + w;
                pq.push({-d[v].F, v});
            }
        }
    }
}
void dijkstra2()
{
    for (int i = 1; i <= n; i ++)
        d[i].S = oo;
    d[2].S = 0;
    priority_queue <pii> pq;
    pq.push({0, 2});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw > d[u].S)
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v].S > dw + w) {
                //bf[v] = u;
                d[v].S = dw + w;
                pq.push({-d[v].S, v});
            }
        }
    }
}
bool cmp(pii a, pii b)
{
    return a.S < b.S;
}
pii dif[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    fi >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        fi >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    dijkstra1();
    dijkstra2();
    ll res = 0ll;
    bool dd[maxn];
    for (int i = 1; i <= n; i ++)
    {
        dif[i].S = i;
        dif[i].F = d[i].F - d[i].S;
    }
    for (int i = 1; i <= n; i ++)
        fo << dif[i].F << endl;
    sort(dif + 1, dif + n + 1);
    for(int i = 1; i <= n; i++){
        if (i <= n/2)
        res += d[dif[i].S].F;
        else
        res += d[dif[i].S].S;
    }
    cout << res;
}

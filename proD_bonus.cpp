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
#define maxn 10005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke_chan[maxn];
vii ke_le[maxn];
int n, k;
int a, b;
int d[maxn];
priority_queue <pii> pq;
void di_chan(int u, int time)
{
    int remain_time = 12 - time % 12;// thời gian còn lại trong ngày
    for (pii x : ke_chan[u])
    {
        int v = x.F;
        int w = x.S;
        if (w <= remain_time && d[v] > w + time)
        {
            d[v] = w + time;
            pq.push({-d[v], v});
        }
    }
}
void di_le(int u, int time)
{
    int remain_time = 12 - time % 12;// thời gian còn lại trong ngày
    for (pii x : ke_le[u])
    {
        int v = x.F;
        int w = x.S;
        if (w <= remain_time && d[v] > w + time)
        {
            d[v] = w + time;
            pq.push({-d[v], v});
        }
    }
}
void Dijkstra()
{
    fill (d + 1, d + n + 1, oo);
    d[a] = 0;
    pq.push({0, a});
    while (!pq.empty())
    {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (d[u] != dw) continue;
        int day = dw / 12 + 1;
        if (day % 2 == 0)
        {
            // nếu đi luôn
            di_chan(u, dw);
            // nếu đợi đến ngày hôm sau
            di_le(u, day * 12);
            // nếu đợi đến khi đường đổi lại chiều
            di_chan(u, (day + 1) * 12);
        }
        else
        {
            // nếu đi luôn
            di_le(u, dw);
            // nếu đợi đến ngày hôm sau
            di_chan(u, day * 12);
            // nếu đợi đến khi đường đổi lại chiều
            di_le(u, (day + 1) * 12);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> a >> b;
    cin >> n >> k;
    for (int i = 1; i <= k; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke_le[u].PB({v, w});
        ke_chan[v].PB({u, w});
    }
    Dijkstra();
    cout << d[b];
}

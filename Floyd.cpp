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
#define maxn 10000
#define MOD
#define Task "minpath"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m, s, t;
ll d[maxn][maxn];
int dd[maxn];
vii ke[maxn];
vi ans;
int trc[maxn];
bool flag = 0;
void floyd()
{
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if(i != k && j != k && i != j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//                    if (d[i][j] > d[i][k] + d[k][j])
//                    {
//                        d[i][j] = d[i][k] + d[k][j];
//                    }
}
void truyvet(int u, int v)
{
    //fo << u << " " << v << " " << "\n";
    dd[u] = 1;
    if (u == v)
    {
        flag = 1;
        return;
    }
    if (flag) return;
    for (pii i : ke[u])
        if (!dd[i.F] && d[u][i.F] + d[i.F][v] == d[u][v] && d[u][i.F] == i.S)
        {
            trc[i.F] = u;
            truyvet(i.F, v);
        }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    fi >> n >> m >> s >> t;
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            d[i][j] = d[j][i] = oo;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        fi >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
        d[u][v] = w;
        d[v][u] = w;
    }
    floyd();
    fo << d[s][t] << "\n";
    truyvet(s, t);
    int x = t;
    while (x != s)
    {
        ans.PB(x);
        x = trc[x];
    }
    ans.PB(s);
    fo << sz(ans) << "\n";
    for (int i = sz(ans) - 1; i >= 0; i --)
        fo << ans[i] << " ";
//    for (int i = 1; i <= n; i ++) {
//        for (int j = 1; j <= n; j ++)
//            fo << d[i][j] << " ";
//        fo << endl;
//    }
}

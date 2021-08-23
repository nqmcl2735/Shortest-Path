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
ll d[maxn];
void Ford()
{
    fill(d + 1, d + n + 1, oo);
    d[s] = 0;
    while (1){
        bool stop = 1;
        for (int u = 1; u <= n; u++)
            for (pii x : ke[u])
            {
                int v = x.F;
                int w = x.S;
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    stop = 0;
                }
            }
        if (stop) break;
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
    Ford();
    cout << d[t];
}

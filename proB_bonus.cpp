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
#define maxn 500
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int d[maxn][maxn];
int bf[maxn];
bool check[maxn];
int w[maxn];
int sol(int s)
{
    reset(w, 60);
    fill(bf + 1, bf + 2 * n + 1, 1);
    fill(check + 1, check + n + 1, 1);
    w[s] = 0;
    check[s + n] = 0;
    while(1){
        int u = 0;
        for(int i = 1; i <= n; i ++)
            if(w[i] < w[u] && check[i]) u = i;
        if(u == 0) break;
        check[u] = 0;
        for(int i = 1; i <= n; i ++)
            if(check[i] && bf[u] != i)
                if(w[i] > w[u] + d[u][i]){
                    w[i + n] = w[i];
                    w[i] = w[u] + d[u][i];
                    bf[i + n] = bf[i];
                    bf[i] = u;
                }
                else if(w[i + n] > w[u] + d[u][i]){
                    w[i + n ] = w[u] + d[u][i];
                    bf[i] = u;
                }
    }
    int ans = oo;
    for(int i = 1; i <= n; i ++){
        if(i == s) continue;
        ans = min(ans, w[i] + w[i + n]);
    }
    return ans;
}
int main() {
    reset(d, 60);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = d[u][v];
    }
    int res = oo;
    for (int i = 1; i <= n; i ++)
        res = min(res, sol(i));
    cout << res;
}

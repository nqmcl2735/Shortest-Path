//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int, int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100000
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct data{
    int v;
    int c, w;
};
vector<data> ke[maxn];
int n, m;
int s, t;
int W;
int Kn[maxn];
int d[maxn];
double Sol(int k){
    fill(d, d + n + 1, oo);
    d[s] = 0;
    priority_queue<pii> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if(dw != d[u])
            continue;
        for(data x : ke[u]){
            if (x.c < k) continue;
            int v = x.v;
            int w = x.w;
            if(d[v] > dw + w){
                d[v] = dw + w;
                pq.push({-d[v], v});
            }
        }
        if (u == t) return d[t] + W / (1.00 * k);
    }
    return oo;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    cin >> s >> t >> W;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        int w, c;
        cin >> u >> v >> c >> w;
        ke[u].PB({v, c, w});
        ke[v].PB({u, c, w});
        Kn[i] = c;
    }
    double res = oo;
    for (int i = 1; i <= m; i ++)
        res = min(res, Sol(Kn[i]));
    printf("%0.2f", res);
}

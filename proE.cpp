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
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
priority_queue <int> d[maxn];
vii ke[maxn];

int n, m, k;
void Dijkstra(){
    priority_queue< pii> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().S;
        int dw = - pq.top().F;
        pq.pop();
        if (!d[u].empty())
        if( d[u].top() == dw || (sz(d[u]) >= k)) continue;
        d[u].push(dw);
        for(pii x : ke[u]){
            int v = x.F;
            int w = x.S;
        if (!d[v].empty())
        if( d[v].top() == dw + w || (sz(d[v]) >= k)) continue;
        pq.push({-(dw + w), v});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    Dijkstra();
    if(d[n].empty()) {
        cout << -1;
        return 0;
    }
    vi res;
    while (!d[n].empty()) {
        res.PB(d[n].top());
        d[n].pop();
    }
    sort(res.begin(), res.end());
    for (int i : res) cout << i << " ";
}

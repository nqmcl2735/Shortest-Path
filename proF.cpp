////ngqminh.cl2735
//#include <bits/stdc++.h>
//#define PB push_back
//#define pii pair <int,int>
//#define vi vector <int>
//#define vii vector <pii>
//#define mpa make_pair
//#define oo INT_MAX
//#define F first
//#define S second
//#define reset(x, i) memset(x,i,sizeof(x))
//#define sz(x) int(x.size())
//#define mp make_pair
//#define maxn 100000
//#define MOD
//#define Task "proF"
//using namespace std;
//ifstream fi(Task".inp");
//ofstream fo(Task".out");
//typedef long long ll;
//typedef long double ld;
//int n, s, t, m1, m2;
//vii kethuy[maxn];
//vii kebo[maxn];
//int d_bo[maxn];
//int d_thuy[maxn];
//vii ke[maxn];
//void ijk_bo()
//{
//    fill(d_bo , d_bo + n + 1, oo);
//    d_bo[t] = 0;
//    priority_queue <pii> pq;
//    pq.push({0, t});
//    while (!pq.empty()) {
//        int u = pq.top().S;
//        int dw = -pq.top().F;
//        pq.pop();
//        if (dw != d_bo[u])
//            continue;
//        for (pii x : kebo[u])
//        {
//            int v = x.F;
//            int w = x.S;
//            if (d_bo[v] > dw + w) {
//                d_bo[v] = dw + w;
//                pq.push({-d_bo[v], v});
//            }
//        }
//    }
//}
//void ijk_thuy()
//{
//    fill(d_thuy , d_thuy + n + 1, oo);
//    d_thuy[t] = 0;
//    priority_queue <pii> pq;
//    pq.push({0, t});
//    while (!pq.empty()) {
//        int u = pq.top().S;
//        int dw = -pq.top().F;
//        pq.pop();
//        if (dw != d_thuy[u])
//            continue;
//        for (pii x : kethuy[u])
//        {
//            int v = x.F;
//            int w = x.S;
//            if (d_thuy[v] > dw + w) {
//                d_thuy[v] = dw + w;
//                pq.push({-d_thuy[v], v});
//            }
//        }
//    }
//}
//void Init()
//{
//    cin >> n >> s >> t;
//    cin >> m1;
//    for (int i = 1; i <= m1; i ++)
//    {
//        int u, v, w;
//        cin >> u >> v >> w;
//        kebo[u].PB({v, w});
//        kebo[v].PB({u, w});
//    }
//    ijk_bo();
//    cin >> m2;
//    for (int i = 1; i <= m2; i ++)
//    {
//        int u, v, w;
//        cin >> u >> v >> w;
//        kethuy[u].PB({v, w});
//        kethuy[v].PB({u, w});
//    }
//    ijk_thuy();
//}
//int inst[maxn];
//int dp[maxn];
//int dd[maxn];
//void DFS(int u){
//    inst[u] = 1;
//    dd[u] = 1;
//    for(pii x : ke[u]){
//        int v = x.F;
//        int w = x.S;
//        if(inst[v]){
//            cout << -1;
//            exit(0);
//        }
//        if(!dd[v]) DFS(v);
//        dp[u] = max(dp[u], dp[v] + w);
//    }
//    inst[u] = 0;
//}
//void Sol()
//{
//    for(int u = 1; u <= n; u ++){
//        for(pii x : kebo[u]) {
//            int v = x.F;
//            int w = x.S;
//            if(d_bo[u] > d_bo[v]) ke[u].PB({v + n, w});
//        }
//        for(pii x : kethuy[u]) {
//            int v = x.F;
//            int w = x.S;
//            if(d_thuy[u] > d_thuy[v]) ke[u + n].PB({v, w});
//        }
//    }
//    DFS(s);
//    cout << dp[s];
//}
//int main() {
//    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
//    Init();
//    Sol();
//}
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
#define maxn 100000
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii keb[maxn];
vii kes[maxn];
int db[maxn];
int ds[maxn];
int n, m, s, t;
vii ke[maxn];
void Dijkstra1()
{
    fill(db , db + n + 1, oo);
    db[s] = 0;
    priority_queue <pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw != db[u])
            continue;
        for (pii x : keb[u])
        {
            int v = x.F;
            int w = x.S;
            if (db[v] > dw + w) {
//                bf[v] = u;
                db[v] = dw + w;
                pq.push({-db[v], v});
            }
        }
    }
}
void Dijkstra2() {
    fill(ds , ds + n + 1, oo);
    ds[s] = 0;
    priority_queue <pii> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw != ds[u])
            continue;
        for (pii x : kes[u])
        {
            int v = x.F;
            int w = x.S;
            if (ds[v] > dw + w) {
//                bf[v] = u;
                ds[v] = dw + w;
                pq.push({-ds[v], v});
            }
        }
    }
}
void Init()
{
    cin >> n >> s >> t;
    swap(s, t);
    cin >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        keb[u].PB({v, w});
        keb[v].PB({u, w});
    }
    Dijkstra1();
    cin >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        kes[u].PB({v, w});
        kes[v].PB({u, w});
    }
    Dijkstra2();
    for (int u = 1; u <= n; u ++)
    {
        for (pii x : keb[u])
        {
            int v = x.F;
            int w = x.S;
            if (db[u] > db[v])
                ke[u].PB({v + n, w});
        }
        for (pii x : kes[u])
        {
            int v = x.F;
            int w = x.S;
            if (ds[u] > ds[v])
                ke[u + n].PB({v, w});
        }
    }
}
int dp[maxn];
int dd[maxn];
int inst[maxn];
bool cct = 0;
void dfs(int u)
{
    inst[u] = 1;
    dd[u] = 1;
    for (pii x : ke[u])
    {
        int v = x.F;
        int w = x.S;
        if (inst[v])
        {
            cout << -1;
            exit(0);
        }
        if (!dd[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + w);
    }
    inst[u] = 0;
}
void Sol()
{
    dfs(t);
    cout << dp[t];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    Init();
    Sol();
}

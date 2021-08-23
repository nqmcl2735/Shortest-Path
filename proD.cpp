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
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
//struct data{
//    int v, w;
//    char type;
//};
//struct man_utd{
//    int d, pos;
//    char tp;
//    bool operator < (const man_utd &x) const{ return (d > x.d);}
//};
//vector<data> ke[maxn];
//int n;
//int d[maxn];
//int Dijkstra()
//{
//    fill(d + 1, d + n + 1, oo);
//    priority_queue <man_utd> pq;
//    d[n] = 0;
//    pq.push({0, n, 'M'});
//    pq.push({0, n, 'G'});
//    while (!pq.empty())
//    {
//        int dw = pq.top().d;
//        int u = pq.top().pos;
//        char tp = pq.top().tp;
//        pq.pop();
//        //fo << u << " " << dw << " " << tp << endl;
//        if (d[u] != dw) continue;
//        for (data x : ke[u])
//        {
//            int v = x.v;
//            int w = x.w;
//            char type = x.type;
//            if (type == tp) continue;
//            if (d[v] > dw + w)
//            {
//                d[v] = dw + w;
//                pq.push({d[v], v, type});
//            }
//        }
//    }
//    return d[1];
//}
vii ke[maxn];
int d[maxn];
int n;
int Dijkstra2()
{
    fill(d , d + 2 * n + 1, oo);
    d[n] = 0;
    d[2 * n] = 0;
    priority_queue <pii> pq;
    pq.push({0, n});
    pq.push({0, 2 * n});
    while (!pq.empty()) {
        int u = pq.top().S;
        int dw = -pq.top().F;
        pq.pop();
        if (dw != d[u])
            continue;
        for (pii x : ke[u])
        {
            int v = x.F;
            int w = x.S;
            if (d[v] > dw + w) {
                //bf[v] = u;
                d[v] = dw + w;
                pq.push({-d[v], v});
            }
        }
    }
    return min(d[1], d[n + 1]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    int u, v, w1, w2;
    char type;
//    while (cin >> u >> v >> w1 >> w2 >> type)
//    {
//        ke[v].PB({u, w2, type});
//        if (type == 'M') type = 'G';
//        else type = 'M';
//        ke[u].PB({v, w1, type});
//    }
//    cout << Dijkstra();
    while (cin >> u >> v >> w1 >> w2 >> type)
    {
        if (type == 'M') {
            ke[u].PB({v + n, w1});
            ke[v + n].PB({u, w2});
        }
        else
        {
            ke[u + n].PB({v, w1});
            ke[v].PB({u + n, w2});
        }
    }
    cout << Dijkstra2();
    fo << x.v << " " << x.w << " " << x.type << endl;
}

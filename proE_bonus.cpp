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
#define maxn 205
#define faifai pair<pii, char>
#define MOD
#define Task "proE_bonus"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, cost1, cost2;
int d[maxn][maxn][30];
struct data{
    int x, y;
    char t;
};
vector <data> ke[maxn][maxn];
char huong[4] = {'L', 'R', 'U', 'D'};
int xdich = 100, ydich = 100;
string s;
struct data2{
    int val, x, y;
    char t;
    bool operator < (const data2 a) const {
        return val > a.val;
    }
};
int dif(char c, char ch)
{
    if (c == ch) return cost1;
    if (c == 'U')
    {
        if (ch == 'D') return cost1 + 2 * cost2;
        else return cost1 + cost2;
    }
    if (c == 'D')
    {
        if (ch == 'U') return cost1 + 2 * cost2;
        else return cost1 + cost2;
    }
    if (c == 'L')
    {
        if (ch == 'R') return cost1 + 2 * cost2;
        else return cost1 + cost2;
    }
    if (c == 'R')
    {
        if (ch == 'L') return cost1 + 2 * cost2;
        else return cost1 + cost2;
    }
}
void dijkstra()
{
    priority_queue <data2> pq;
    for(int i = 0; i <= 200; i ++)
        for(int j = 0; j <= 200; j ++)
            for(int z = 0; z < 4; z ++)
                d[i][j][huong[z] - 'A'] = oo;
    for(int k = 0; k < 4; ++ k)
        d[100][100][huong[k] - 'A'] = 0;
    pq.push({0, 100, 100, 'Z'});
    while(!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int dw = - pq.top().val;
        char t = pq.top().t;
        pq.pop();
        if (t == 'Z')
            for (data s : ke[x][y])
            {
                int x2 = s.x;
                int y2 = s.y;
                char ch = s.t;
                if (d[x2][y2][ch - 'A'] > dw + cost1)
                {
                    d[x2][y2][ch - 'A'] = dw + cost1;
                    pq.push({- d[x2][y2][ch - 'A'], x2, y2, ch});
                }
            }
        else {
            if(d[x][y][t - 'A'] != dw) continue;
            for (data s : ke[x][y]) {
                int x2 = s.x;
                int y2 = s.y;
                char ch = s.t;
                int cst = dif(ch, t);
                if (d[x2][y2][ch - 'A'] > dw + cst)
                {
                    d[x2][y2][ch - 'A'] = dw + cst;
                    pq.push({- d[x2][y2][ch - 'A'], x2, y2, ch});
                }
            }
        }
    }
}
void sol()
{
    dijkstra();
    int res = oo;
    for(int k = 0; k < 4; ++ k)
        res = min(res, d[xdich][ydich][huong[k] - 'A']);
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> cost1 >> cost2;
    cin >> n;
    cin >> s;
    for (char ch : s)
    {
        int x = xdich;
        int y = ydich;
        if (ch == 'U') ydich ++;
        if (ch == 'D') ydich --;
        if (ch == 'R') xdich ++;
        if (ch == 'L') xdich --;
        ke[x][y].PB({xdich, ydich, ch});
    }
    sol();
}

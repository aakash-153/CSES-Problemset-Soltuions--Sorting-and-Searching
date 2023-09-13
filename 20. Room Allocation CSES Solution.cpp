#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

int main()
{
    int n;
    cin >> n;
    vvi s(n, vi(2)), e(n, vi(2));

    vi rooms(n);
    stack<int> available;
    int k = 0, curr = 0;

    REP(i, n)
    {
        cin >> s[i][0] >> e[i][0];

        s[i][1] = i;
        e[i][1] = i;

        available.push(i + 1);
    }

    SORT(s);
    SORT(e);

    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (s[i][0] <= e[j][0])
        {
            curr++;
            rooms[s[i][1]] = available.top();
            available.pop();
            i++;
        }
        else
        {
            curr--;
            available.push(rooms[e[j][1]]);
            j++;
        }
        k = max(k, curr);
    }

    cout << k << endl;
    REP(i, n)
    cout << rooms[i] % k + 1 << " ";

    return 0;
}
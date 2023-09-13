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

bool compare(vi &a, vi &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}

int main()
{
    int n;
    cin >> n;
    vvi a(n, vi(3));

    REP(i, n)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(ALL(a), compare);

    vi contains(n);
    vi contained(n);

    multiset<int> s;

    REP(i, n)
    s.insert(a[i][1]);

    REP(i, n)
    {
        s.erase(s.lower_bound(a[i][1]));

        auto it = s.upper_bound(a[i][1]);

        contains[a[i][2]] = !(it == s.begin());
    }

    REP(i, n)
    s.insert(a[i][1]);

    for (int j = n - 1; j >= 0; j--)
    {
        s.erase(s.lower_bound(a[j][1]));

        auto it = s.lower_bound(a[j][1]);

        contained[a[j][2]] = !(it == s.end());
    }

    REP(i, n)
    {
        cout << contains[i] << " ";
    }

    cout << "\n";

    REP(i, n)
    {
        cout << contained[i] << " ";
    }

    return 0;
}

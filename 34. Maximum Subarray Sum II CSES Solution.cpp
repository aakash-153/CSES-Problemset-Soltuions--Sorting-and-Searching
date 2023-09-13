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
    int n, a, b;
    cin >> n >> a >> b;
    long long sum = 0;
    long long ans = LLONG_MIN;

    vl A(n);

    REP(i, n)
    {
        int x;
        cin >> x;
        sum += x;
        A[i] = sum;
    }

    multiset<long long> s;

    for (int i = 0; i + a < n; i++)
    {
        if (i == 0)
        {
            for (int j = i + a; j <= n - 1 && j <= i + b; j++)
                s.insert(A[j]);
        }
        else
        {
            s.erase(s.lower_bound(A[i - 1 + a]));
            if (i + b < n)
                s.insert(A[i + b]);
        }

        auto it = s.end();
        it--;

        ans = max(ans, *(it)-A[i]);
    }

    for (int i = a - 1; i <= b - 1 && i < n; i++)
        ans = max(ans, A[i]);

    cout << ans;
}
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

class Node
{
public:
    int val;
    Node *next;

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

int main()
{
    int n;
    cin >> n;

    Node *head = new Node(1);
    Node *tail = head;

    for (int i = 2; i <= n; i++)
    {
        Node *newnode = new Node(i);

        tail->next = newnode;
        tail = newnode;
    }

    tail->next = head;

    Node *curr = head;

    while (curr->next != curr)
    {
        cout << curr->next->val << " ";
        Node *temp = curr->next->next;
        Node *temp2 = curr->next;
        temp2->next = NULL;
        delete temp2;
        curr->next = temp;
        curr = curr->next;
    }

    cout << curr->val;
    delete curr;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1'000'000'007LL;
const int INF = 2'000'000'000;
const ll LL_INF = 10'000'000'000LL;

const int MAX = 100001;
int n, m;
int numbers[MAX];
vector<int> mergeSortTree[4 * MAX];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        mergeSortTree[v] = vector<int>(1, numbers[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge(
                mergeSortTree[2 * v].begin(),
                mergeSortTree[2 * v].end(),
                mergeSortTree[2 * v + 1].begin(),
                mergeSortTree[2 * v + 1].end(),
                back_inserter(mergeSortTree[v])
                );
    }
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        vector<int>::iterator pos = upper_bound(mergeSortTree[v].begin(), mergeSortTree[v].end(), x);
        return mergeSortTree[v].end() - pos;
    }

    int tm = (tl + tr) / 2;
    int left = query(2 * v, tl, tm, l, min(r, tm), x);
    int right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x);
    return left + right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }

    build(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << query(1, 1, n, a, b, c) << "\n";
    }
    
    return 0;
}
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

typedef long long ll;
const ll LL_INF = 10000000000LL;
const int INF = 2000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

int n, m;
int parent[500001];
int depth[500001];

void makeSet(int v) {
    parent[v] = v;
    depth[v] = 0;
}

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

bool unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            depth[a]++;
        return false;
    } else {
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        makeSet(i);
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;

        bool result = unionSet(a, b);

        if (ans == 0 && result) {
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
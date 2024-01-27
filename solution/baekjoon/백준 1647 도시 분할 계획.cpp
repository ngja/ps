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

// union-find
vector<int> parent, depth;

void make_set(int v) {
    parent[v] = v;
    depth[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            depth[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n, m;
vector<Edge> edges;

int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    cin >> n >> m; // 집, 길
    parent.resize(n+1);
    depth.resize(n+1);

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; // 집 a ~ 집 b 연결 유지비 c
        cin >> a >> b >> c;
        edges.push_back(Edge({a, b, c}));
    }

    // kruskal algorithm
    sort(edges.begin(), edges.end());

    int cost = 0;
    int edgeCount = 0;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            edgeCount++;
            if (edgeCount == (n-1)) {
                break;
            }
            cost += e.weight;
            union_set(e.u, e.v);
        }
    }

    cout << cost;
}
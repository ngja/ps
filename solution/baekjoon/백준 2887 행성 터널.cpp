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

vector<ll> parent, depth;

void make_set(ll v) {
    parent[v] = v;
    depth[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(ll a, ll b) {
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
    ll u, v;
    ll weight;

    bool operator<(Edge const &other) const {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<pair<ll, ll>> dots[3];

    for (auto & dot : dots) {
        dot.resize(n);
    }

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        dots[0][i] = {x, i};
        dots[1][i] = {y, i};
        dots[2][i] = {z, i};
    }

    for (auto & dot : dots) {
        sort(dot.begin(), dot.end());
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            Edge edge{};
            edge.u = dots[j][i-1].second;
            edge.v = dots[j][i].second;
            edge.weight = abs(dots[j][i-1].first - dots[j][i].first);
            edges.push_back(edge);
        }
    }

    sort(edges.begin(), edges.end());

    ll cost = 0;
    parent.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);
    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_set(e.u, e.v);
        }
    }

    cout << cost << "\n";

    return 0;
}
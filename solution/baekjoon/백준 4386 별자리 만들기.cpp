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

using namespace std;

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

void union_sets(int a, int b) {
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
    int u, v;
    double weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    vector<pair<double, double>> points;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Edge edge = Edge();
            edge.u = i;
            edge.v = j;
            edge.weight = sqrt(pow(points[i].first - points[j].first, 2.0) + pow(points[i].second - points[j].second, 2.0));
            edges.push_back(edge);
        }
    }

    double cost = 0;
    vector<Edge> result;
    parent.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << cost << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
const ll INF = 10000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;
vector<tuple<int, int, ll>> edges;
ll dist[505];

int main() {

    cin >> n >> m;
    edges.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
    }

    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < n-1; ++i) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            if (dist[a] != INF)
                dist[b] = min(dist[b], dist[a] + w);
        }
    }

    bool minusCycle = false;
    for (auto e : edges) {
        int a, b, w;
        tie(a, b, w) = e;
        if (dist[a] != INF && dist[b] > dist[a] + w) {
            minusCycle = true;
            break;
        }
    }

    if (minusCycle)
        cout << -1 << "\n";
    else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }

    return 0;
}

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
const ll INF = 100000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int v, e;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<ll, int>> q;
ll dist[808];
bool visited[808];

void dijkstra(int s) {
    fill(dist, dist+v+1, INF);
    fill(visited, visited+v+1, false);
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int from = q.top().second; q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        for (pair<int, int> next : graph[from]) {
            int to = next.first, len = next.second;
            if (dist[from] + len < dist[to]) {
                dist[to] = dist[from] + len;
                q.push({-dist[to], to});
            }
        }
    }
}


int main() {

    cin >> v >> e;
    graph.resize(v+1);

    for (int i = 0; i < e; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    int must1, must2;
    cin >> must1 >> must2;

    ll candidate1 = 0; // 1 -> must1 -> must2 -> N
    ll candidate2 = 0; // 1 -> must2 -> must1 -> N

    // 1
    dijkstra(1);
    if (must1 != 1) {
        candidate1 += dist[must1]; // 1 -> must1
    }
    if (must2 != 1) {
        candidate2 += dist[must2]; // 1 -> must2
    }

    // must1
    dijkstra(must1);
    candidate1 += dist[must2]; // must1 -> must2
    if (must1 != v) {
        candidate2 += dist[v]; // must1 -> N
    }

    // must2
    dijkstra(must2);
    if (must2 != v) {
        candidate1 += dist[v]; // must2 -> N
    }
    candidate2 += dist[must1]; // must2 -> must1

    ll ans = min(candidate1, candidate2);

    if (ans >= INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}

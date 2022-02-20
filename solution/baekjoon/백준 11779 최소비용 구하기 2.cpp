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
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;

int main() {

    cin >> n;
    cin >> m;

    vector<vector<pair<int, int>>> bus(n+1);
    vector<int> dist;
    vector<int> parent;
    vector<int> visited;
    dist.assign(n+1, INF);
    parent.assign(n+1, -1);
    visited.assign(n+1, false);

    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        bus[a].push_back({b, d});
    }

    int from, to;
    cin >> from >> to;

    priority_queue<pair<int, int>> q;
    dist[from] = 0;
    parent[from] = from;
    q.push({0, from});
    while(!q.empty()) {
        int current = q.top().second; q.pop();
        if (visited[current]) continue;
        visited[current] = true;
        for (pair<int, int> u : bus[current]) {
            int next = u.first;
            int w = u.second;
            if (dist[next] > dist[current] + w) {
                dist[next] = dist[current] + w;
                parent[next] = current;
                q.push({-dist[next], next});
            }
        }
    }

    stack<int> tail;
    int t = to;
    while(parent[t] != t) {
        tail.push(t);
        t = parent[t];
    }
    tail.push(from);

    cout << dist[to] << "\n";
    cout << tail.size() << "\n";
    while(!tail.empty()) {
        cout << tail.top() << " ";
        tail.pop();
    }

    return 0;
}

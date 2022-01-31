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

int t, n, k;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& topology) {
    visited[v] = true;

    for (int next : graph[v]) {
        if (visited[next])
            continue;
        dfs(next, visited, graph, topology);
    }
    topology.push(v);
}

int main() {

    cin >> t;

    while (t--) {
        cin >> n >> k;
        vector<int> costs;
        costs.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> costs[i + 1];
        }

        vector<vector<int>> graph;
        graph.resize(n + 1);
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        int target;
        cin >> target;

        // topological sort
        vector<bool> visited;
        visited.resize(n + 1, false);
        stack<int> topology;

        for (int i = 0; i < n; ++i) {
            if (visited[i+1])
                continue;
            dfs(i+1, visited, graph, topology);
        }

        // total cost 계산
        vector<int> totalCosts;
        totalCosts.resize(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            totalCosts[i+1] = costs[i+1];
        }

        while (!topology.empty()) {
            int current = topology.top();
            topology.pop();

            for (int next : graph[current]) {
                totalCosts[next] = max(totalCosts[next], totalCosts[current] + costs[next]);
            }
        }

        cout << totalCosts[target] << "\n";
    }


    return 0;
}
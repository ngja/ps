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

vector<bool> visited;
vector<bool> finished;
vector<int> parent;
vector<vector<int>> graph;
int ans;

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[u] = v;
            dfs(v);
        } else if (!finished[v]) {
            int p = v;
            while (p != u) {
                ans--;
                p = parent[p];
            }
            ans--;
        }
    }
    finished[u] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ans = n;

        graph.assign(n + 1, vector<int>());
        parent.assign(n + 1, 0);
        visited.assign(n + 1, false);
        finished.assign(n + 1, false);

        int want;
        for (int i = 1; i <= n; i++) {
            cin >> want;
            graph[i].push_back(want);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;
            dfs(i);
        }

        cout << ans << "\n";
    }

    return 0;
}
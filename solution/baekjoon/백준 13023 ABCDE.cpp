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

int n, m;
vector<int> adj[2005];
bool visited[2005];
bool ans = false;

void dfs(int s, int depth) {
    visited[s] = true;
    if (depth >= 4) {
        ans = true;
        return;
    }
    for (auto u : adj[s]) {
        if (!visited[u]) {
            dfs(u, depth+1);
            visited[u] = false;
        }
    }
}

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        fill(visited, visited + n, false);
        dfs(i, 0);

        if (ans) {
            cout << 1 << "\n";
            break;
        }
    }

    if (!ans) {
        cout << 0 << "\n";
    }

    return 0;
}
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
vector<vector<int>> graph;
vector<vector<int>> reverseGraph;
bool visited[20020];
stack<int> st;
int scc[20020];

int notOperation(int a) {
    if (a > n)
        return a - n;
    else
        return a + n;
}

void dfs(int v) {
    visited[v] = true;
    for (int next : graph[v]) {
       if (visited[next])
           continue;
       dfs(next);
    }
    st.push(v);
}

void kosaraju(int v, int c) {
    visited[v] = true;
    scc[v] = c;
    for (int next : reverseGraph[v]) {
        if (visited[next])
            continue;
        kosaraju(next, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.assign(2 * n + 2, vector<int> ());
    reverseGraph.assign(2 * n + 2, vector<int> ());

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a = (a > 0) ? a : n - a;
        b = (b > 0) ? b : n - b;

        // not a -> b
        graph[notOperation(a)].push_back(b);
        reverseGraph[b].push_back(notOperation(a));

        // not b -> a
        graph[notOperation(b)].push_back(a);
        reverseGraph[a].push_back(notOperation(b));
    }

    // kosaraju
    for (int i = 1; i <= 2 * n; i++) {
        if (visited[i])
            continue;
        dfs(i);
    }

    fill(visited, visited + (2 * n + 2), false);

    int groupNo = 1;
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (visited[cur])
            continue;

        kosaraju(cur, groupNo++);
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[notOperation(i)]) {
            possible = false;
            break;
        }
    }

    if (possible)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
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

int n, m;
set<int> adj[1010];
bool visited[1010];
bool finished[1010];
bool cycle;
stack<int> topology;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u])
            dfs(u);
        else if (!finished[u])
           cycle = true;
    }
    finished[s] = true;
    topology.push(s);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int singerNumber;
        cin >> singerNumber;
        vector<int> singers(singerNumber);
        for (int j = 0; j < singerNumber; ++j) {
            cin >> singers[j];
        }

        for (int j = 0; j < singerNumber; ++j) {
            for (int k = j + 1; k < singerNumber; ++k) {
                adj[singers[j]].insert(singers[k]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }

    if (cycle) {
        cout << "0\n";
    } else {
        while(!topology.empty()) {
            cout << topology.top() << "\n";
            topology.pop();
        }
    }

    return 0;
}
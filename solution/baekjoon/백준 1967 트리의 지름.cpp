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

const int INF = ~(1 << 31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n;
vector<vector<pair<int, int>>> tree;
bool visited[10005];
int ans = 0;
int candidate = 0;

void dfs(int s, int len) {
    if (visited[s]) return;
    if (ans < len) {
        ans = len;
        candidate = s;
    }
    visited[s] = true;
    for (pair<int, int> next : tree[s]) {
        dfs(next.first, len + next.second);
    }
}

int main() {

    cin >> n;
    tree.resize(n+1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a].push_back({b, w});
        tree[b].push_back({a, w});
    }

    dfs(1, 0);
    fill(visited, visited+n+1, false);
    ans = 0;
    dfs(candidate, 0);

    cout << ans << "\n";

    return 0;
}

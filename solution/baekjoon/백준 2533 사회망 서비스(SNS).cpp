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

int n;
vector<vector<int>> adj;
// dp[i][0] = 정점 i 가 일반인일 때 서브트리의 얼리어답터 최소수
// dp[i][1] = 정점 i 가 얼리어답터일 때 서브트리의 얼리어답터 최소수
vector<vector<int>> dp;

void dfs(int s, int e) {
    bool isLeaf = true;
    for (int next : adj[s]) {
        if (next != e) {
            dfs(next, s);
            isLeaf = false;
        }
    }

    if (isLeaf) {
        dp[s][0] = 0;
        dp[s][1] = 1;
        return;
    }

    int early = 1;
    int notEarly = 0;
    for (int next : adj[s]) {
        if (next == e) continue;
        notEarly += dp[next][1];
        early += min(dp[next][0], dp[next][1]);
    }
    dp[s][0] = notEarly;
    dp[s][1] = early;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n + 1, {INF, INF});

    dfs(1, 0);
    int ans = min(dp[1][0], dp[1][1]);
    cout << ans << "\n";
}
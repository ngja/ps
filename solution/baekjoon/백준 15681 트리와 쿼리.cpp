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

int n, r, q; // n=정점 수, r=루트 번호, q=쿼리 수
vector<int> adj[100001];
int dp[100001];

void dfs(int s, int e) {
    dp[s] = 1;
    for (int next : adj[s]) {
        if (next == e) continue;
        dfs(next, s);
        dp[s] += dp[next];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(r, 0);

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }
}
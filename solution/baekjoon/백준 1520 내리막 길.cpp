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

const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

int m, n;
int world[501][501];
int dp[501][501]; // (i, j)에 도착했을때 우하단까지 가는 수

vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < m) && (x >= 0) && (x < n);
}

int dfs(int y, int x) { // dp[y][x]를 구하는 식

    if ((y == (m-1)) && (x == (n-1))) {
        return 1;
    }
    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    dp[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nextY = y + dirs[i].first;
        int nextX = x + dirs[i].second;

        if (!isIn(nextY, nextX)) {
            continue;
        }

        if (world[nextY][nextX] >= world[y][x]) {
            continue;
        }

        dp[y][x] += dfs(nextY, nextX);
    }

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> world[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = dfs(0, 0);

    cout << ans << "\n";

    return 0;
}
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

int n, m;
char world[1010][1010];
bool visited[1010][1010];
bool finished[1010][1010];
int ans;

pair<int, int> convertDirToIndex(char c) {
    if (c == 'U') {
        return {-1, 0};
    } else if (c == 'D') {
        return {1, 0};
    } else if (c == 'L') {
        return {0, -1};
    } else {
        return {0, 1};
    }
}

void dfs(int y, int x) {
    if (visited[y][x]) return;

    visited[y][x] = true;

    pair<int, int> dir = convertDirToIndex(world[y][x]);

    int nextY = y + dir.first;
    int nextX = x + dir.second;
    if (!visited[nextY][nextX]) {
        dfs(nextY, nextX);
    } else if (!finished[nextY][nextX]) {
        ans++;
    }

    finished[y][x] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> world[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j])
                continue;
            dfs(i, j);
        }
    }

    cout << ans << "\n";

    return 0;
}
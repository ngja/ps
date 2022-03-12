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
char gameBoard[55][55];
int depth[55][55];
bool visited[55][55];
bool finished[55][55];
bool cycle = false;

vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < m);
}

void dfs(int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = true;
    for (pair<int, int> dir : dirs) {
        int nextY = y + dir.first;
        int nextX = x + dir.second;

        if (!isIn(nextY, nextX))
            continue;

        if (gameBoard[y][x] != gameBoard[nextY][nextX])
            continue;

        if (!visited[nextY][nextX]) {
            depth[nextY][nextX] = depth[y][x] + 1;
            dfs(nextY, nextX);
        } else if (!finished[nextY][nextX]) {
            int count = abs(depth[nextY][nextX] - depth[y][x]);
            if (count >= 3) {
                cycle = true;
            }
        }
    }
    finished[y][x] = true;
}

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> gameBoard[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if (visited[i][j])
                continue;
            depth[i][j] = 1;
            dfs(i, j);
        }
    }

    if (cycle) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
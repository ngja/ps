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

int n, m;
int world[1001][1001];
int group[1001][1001];
int groupCount[1000000];
int ans[1001][1001];

vector<pair<int, int>> dirs {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < m);
}

int dfs(int y, int x, int g) {
    group[y][x] = g;

    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        pair<int, int> dir = dirs[i];
        int nextY = y + dir.first;
        int nextX = x + dir.second;

        if (!isIn(nextY, nextX)) {
            continue;
        }

        if (world[nextY][nextX] == 1) {
            continue;
        }

        if (group[nextY][nextX] != 0) {
            continue;
        }

        ret += dfs(nextY, nextX, g);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            world[i][j] = c - '0';
        }
    }

    int groupId = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (world[i][j] == 0 && group[i][j] == 0) {
                int groupValue = dfs(i, j, groupId);
                groupCount[groupId] = groupValue % 10;
                groupId++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (world[i][j] == 1) {
                int temp = 1;
                set<int> groupSet;
                for (int k = 0; k < 4; ++k) {
                    int nextY = i + dirs[k].first;
                    int nextX = j + dirs[k].second;

                    if (!isIn(nextY, nextX)) {
                        continue;
                    }

                    int tempGroupId = group[nextY][nextX];

                    if (groupSet.find(tempGroupId) == groupSet.end()) {
                        temp += groupCount[group[nextY][nextX]];
                        groupSet.insert(tempGroupId);
                    }
                }
                ans[i][j] = temp % 10;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << "\n";
    }


    return 0;
}
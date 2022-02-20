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

typedef long long ll;
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;
int cheese[105][105];
pair<int, int> dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isIn(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < n) && (x < m);
}

int main() {

    cin >> n >> m;
    int cheeseCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cheese[i][j];
            if (cheese[i][j] == 1)
                cheeseCount++;
        }
    }

    int ans = 0;

    while (cheeseCount != 0) {

        queue<pair<int, int>> q;
        int melt[105][105] = {0, };
        bool visited[105][105] = {false, };
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for (pair<int, int> d : dir) {
                int nextY = cur.first + d.first;
                int nextX = cur.second + d.second;
                if (isIn(nextY, nextX)) {
                    if (cheese[nextY][nextX] == 1) {
                        melt[nextY][nextX] += 1;
                    } else if (cheese[nextY][nextX] == 0) {
                        if (!visited[nextY][nextX]) {
                            q.push({nextY, nextX});
                            visited[nextY][nextX] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (melt[i][j] >= 2) {
                    cheese[i][j] = 0;
                    cheeseCount--;
                }
            }
        }

        ans++;

        if (cheeseCount == 0)
            break;

    }

    cout << ans << "\n";

    return 0;
}

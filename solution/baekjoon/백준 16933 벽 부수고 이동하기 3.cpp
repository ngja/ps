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

int n, m, k;

int world[1001][1001];
bool visited[1001][1001][11][2]; // [i][j][k][l] (i, j)번째에 k개의 벽을 부스고 낮밤일때 도달한 여부

vector<pair<int, int>> dirs = {
        {0, 0},
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

struct Position {
    int y;
    int x;
    int crash;
    int distance;
    int night;
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            world[i][j] = c - '0';
        }
    }

    queue<Position> q;
    Position start = {0, 0, 0, 1, 0};
    visited[0][0][0][0] = true;
    q.push(start);

    int ans = INF;
    while(!q.empty()) {
        Position cur = q.front();
        q.pop();

        if ((cur.y == (n-1)) && (cur.x == (m-1))) {
            ans = min(ans, cur.distance);
        }

        for (int idx = 0; idx < 5; idx++) {
            // 아침에는 동일 위치에 있을 필요가 없음
            pair<int, int> dir = dirs[idx];
            if (cur.night == 0) {
                if (idx == 0) {
                    continue;
                }
            }

            int nextY = cur.y + dir.first;
            int nextX = cur.x + dir.second;

            if (!isIn(nextY, nextX)) {
                continue;
            }

            Position nextPos = {nextY, nextX, cur.crash, cur.distance + 1, cur.night};
            if (world[nextY][nextX] == 1 && idx != 0) {
                if (cur.crash >= k) {
                    continue;
                }
                if (cur.night == 1) {
                    continue;
                }
                nextPos.crash += 1;
            }

            nextPos.night = !nextPos.night;
            if (visited[nextPos.y][nextPos.x][nextPos.crash][nextPos.night]) {
                continue;
            }

            visited[nextPos.y][nextPos.x][nextPos.crash][nextPos.night] = true;
            q.push(nextPos);
        }
    }

    if (ans == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
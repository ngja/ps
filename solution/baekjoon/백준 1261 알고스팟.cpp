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

pair<int, int> dirs[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int maze[101][101];
int breakCount[101][101];
bool processed[101][101];

int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char input;
            cin >> input;
            maze[i][j] = input - '0';
            breakCount[i][j] = INF;
        }
    }

    // 다익스트라
    priority_queue<pair<int, pair<int, int>>> q; // {-벽 부순 횟수, 좌표}
    q.push({0, {0, 0}});
    breakCount[0][0] = 0;
    while(!q.empty()) {
        pair<int, pair<int, int>> now = q.top(); q.pop();
        int nowBreakCount = -now.first;
        pair<int, int> nowPos = now.second;
        if (processed[nowPos.first][nowPos.second]) continue;
        processed[nowPos.first][nowPos.second] = true;

        for (pair<int, int> dir : dirs) {
            pair<int, int> nextPos = {nowPos.first + dir.first, nowPos.second + dir.second};

            if (nextPos.first < 0 || nextPos.first >= m || nextPos.second < 0 || nextPos.second >= n) {
                continue;
            }

            if (processed[nextPos.first][nextPos.second])
                continue;

            // 벽을 부순다면 개수가 더 적은거
            if (breakCount[nextPos.first][nextPos.second] > breakCount[nowPos.first][nowPos.second] + maze[nextPos.first][nextPos.second]) {
                breakCount[nextPos.first][nextPos.second] = breakCount[nowPos.first][nowPos.second] + maze[nextPos.first][nextPos.second];
                q.push({-breakCount[nextPos.first][nextPos.second], {nextPos.first, nextPos.second}});
            }
        }
    }

    cout << breakCount[m-1][n-1];
}
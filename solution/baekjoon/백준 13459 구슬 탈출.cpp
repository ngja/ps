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
char board[11][11];
bool visited[11][11][11][11];

vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

struct Position {
    pair<int, int> red;
    pair<int, int> blue;
    int moveCount;
    int beforeDir;
};

bool cantMove(int y, int x, pair<int, int> blocking) {
    return board[y][x] == '#' || (y == blocking.first && x == blocking.second);
}

pair<int, int> moveBall(pair<int, int> ball, pair<int, int> blocking, int dirIndex) {
    int y = ball.first;
    int x = ball.second;

    while(true) {

        int nextY = y + dirs[dirIndex].first;
        int nextX = x + dirs[dirIndex].second;

        if (cantMove(nextY, nextX, blocking)) {
            break;
        }

        y = nextY;
        x = nextX;

        if (board[y][x] == 'O')
            break;
    }

    // 만약 구멍에 빠지는 경우 {10, 10}으로 다음 이동에 영향 받지 않도록 리턴
    if (board[y][x] == 'O') {
        return {10, 10};
    }

    return {y, x};
}

void printPosition(Position p) {
    cout << "Position -: moveCount: " << p.moveCount << ", beforeDir: " << p.beforeDir << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == p.red.first && j == p.red.second) {
                cout << "R";
            } else if (i == p.blue.first && j == p.blue.second) {
                cout << "B";
            } else {
                cout << board[i][j];
            }
        }
        cout << "\n";
    }
    cout << "======================================\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    Position firstPosition = {};
    firstPosition.moveCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                firstPosition.red = {i, j};
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                firstPosition.blue = {i, j};
                board[i][j] = '.';
            }
        }
    }

    queue<Position> q;
    firstPosition.beforeDir = -1;
    q.push(firstPosition);

    int ans = INF;

    while(!q.empty()) {
        Position cur = q.front();
        q.pop();
        visited[cur.red.first][cur.red.second][cur.blue.first][cur.blue.second] = true;

        if (cur.moveCount > 10) {
            continue;
        }

        // 4방향
        for (int i = 0; i < 4; ++i) {
            if (i == cur.beforeDir)
                continue;

            bool redFirst = true;
            pair<int, int> firstMoveBall;
            pair<int, int> lastMoveBall;

            // 빨간공, 파란공 중 먼저 움직일 것 선택
            if (i == 0) { // 아래 있는 공 부터
                if (cur.red.first > cur.blue.first) {
                    redFirst = true;
                } else {
                    redFirst = false;
                }
            } else if (i == 1) { // 오른쪽에 있는 공 부터
                if (cur.red.second > cur.blue.second) {
                    redFirst = true;
                } else {
                    redFirst = false;
                }
            } else if (i == 2) { // 위에 있는 공부터
                if (cur.red.first < cur.blue.first) {
                    redFirst = true;
                } else {
                    redFirst = false;
                }
            } else if (i == 3) { // 왼쪽에 있는 공 부터
                if (cur.red.second < cur.blue.second) {
                    redFirst = true;
                } else {
                    redFirst = false;
                }
            }

            bool possible = false;

            if (redFirst) {
                firstMoveBall = moveBall(cur.red, cur.blue, i);

                if (firstMoveBall.first == 10 && firstMoveBall.second == 10) { // 구멍에 빠짐
                    possible = true;
                }

                lastMoveBall = moveBall(cur.blue, firstMoveBall, i);

                if (lastMoveBall.first == 10 && lastMoveBall.second == 10) {
                    continue;
                }

            } else {
                firstMoveBall = moveBall(cur.blue, cur.red, i);

                if (firstMoveBall.first == 10 && firstMoveBall.second == 10) {
                    continue;
                }

                lastMoveBall = moveBall(cur.red, firstMoveBall, i);

                if (lastMoveBall.first == 10 && lastMoveBall.second == 10) {
                    possible = true;
                }
            }

            if (possible) {
                ans = min(ans, cur.moveCount + 1);
                continue;
            }

            // next enqueue
            Position nextPosition = {lastMoveBall, firstMoveBall, cur.moveCount + 1, i};
            if (redFirst) {
                nextPosition.red = firstMoveBall;
                nextPosition.blue = lastMoveBall;
            }
            if (nextPosition.moveCount > 10)
                continue;

            if (visited[nextPosition.red.first][nextPosition.red.second][nextPosition.blue.first][nextPosition.blue.second]) {
                continue;
            }

            q.push(nextPosition);
        }
    }

    if (ans > 10)
        cout << 0 << "\n";
    else
        cout << 1 << "\n";

    return 0;
}
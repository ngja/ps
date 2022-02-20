#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

char cave[102][102];
int r, c;
int n;
int mineralCount = 0;
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<pair<int, int>>> fallTarget;

bool isIn(int y, int x) {
    return (y <= r) && (x <= c) && (y > 0) && (x > 0);
}

void destroy(int h, bool isRight) {
    if (isRight) {
        for (int i = c; i >= 1; --i) {
            if (cave[h][i] == 'x') {
                cave[h][i] = '.';
                mineralCount--;
                break;
            }
        }
    } else {
        for (int i = 1; i <= c; ++i) {
            if (cave[h][i] == 'x') {
                cave[h][i] = '.';
                mineralCount--;
                break;
            }
        }
    }
}

void checkFall() {
    bool visited[102][102] = {false, };
    fallTarget.clear();
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            // bfs begin
            if (cave[i][j] == 'x' && !visited[i][j]) {
                int tempMineralCount = 0;
                int minHeight = 0;

                vector<pair<int, int>> group;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while(!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    group.push_back(cur);
                    tempMineralCount++;
                    minHeight = max(minHeight, cur.first);

                    for (auto & d : dir) {
                        int nextY = cur.first + d.first;
                        int nextX = cur.second + d.second;

                        if (isIn(nextY, nextX)) {
                            if (cave[nextY][nextX] == 'x' && !visited[nextY][nextX]) {
                                visited[nextY][nextX] = true;
                                q.push({nextY, nextX});
                            }
                        }
                    }
                }

                if (tempMineralCount == mineralCount && minHeight == r) {
                    return;
                } else if (minHeight == r) {
                    // ³«ÇÏ ¾Æ´Ô

                } else {
                    // ³«ÇØ ´ë»ó
                    fallTarget.push_back(group);
                }
            }
        }
    }
}

void fall() {
    for (vector<pair<int, int>> target : fallTarget) {
        int minFallHeight = INF;
        for (pair<int, int> dot : target) {
            int fallHeight = 0;
            for (int down = 1; dot.first + down <= r; down++) {
                if (cave[dot.first+down][dot.second] == '.')
                    fallHeight++;
                else if (cave[dot.first+down][dot.second] == 'x') {
                    for (pair<int, int> inside : target) {
                        if (dot.first+down == inside.first && dot.second == inside.second) {
                            fallHeight = 0;
                        }
                    }
                    break;
                }
            }

            if (fallHeight != 0) {
                minFallHeight = min(minFallHeight, fallHeight);
            }
        }

        if (minFallHeight == INF)
            continue;

        for (pair<int, int> dot : target) {
            cave[dot.first][dot.second] = '.';
        }
        for (pair<int, int> dot : target) {
            cave[dot.first+minFallHeight][dot.second] = 'x';
        }
    }
}

int main() {

    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> cave[i][j];
            if (cave[i][j] == 'x')
                mineralCount++;
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;

        bool isRight = i & 1;

        destroy(r - height + 1, isRight);
        checkFall();
        fall();
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cout << cave[i][j];
        }
        cout << "\n";
    }

    return 0;
}

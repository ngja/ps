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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char lake[1505][1505];
bool visited[1505][1505];
queue<pair<int, int>> swan;
queue<pair<int, int>> water;
int r, c;

bool isIn(int y, int x) {
    return (y < r && r >= 0 && x < c && x >= 0);
}

int main() {
//    freopen("labudovi.i13", "r", stdin);

//    scanf("%d %d", &r, &c);
    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
//            char cr;
//            scanf(" %c", &cr);
//            lake[i][j] = cr;
            cin >> lake[i][j];
            if (lake[i][j] == '.') {
                water.push({i, j});
            } else if (lake[i][j] == 'L') {
                water.push({i, j});
                if (swan.empty()) {
                    swan.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
    }

    // πÈ¡∂ bfs
    int time = 0;
    while(true) {
        while(!swan.empty()) {
            pair<int, int> cur = swan.front(); swan.pop();

            for (pair<int, int> d : dir) {
                int nextY = cur.first + d.first;
                int nextX = cur.second + d.second;

                if (isIn(nextY, nextX)) {
                    if (lake[nextY][nextX] == '.' && !visited[nextY][nextX]) {
                        visited[nextY][nextX] = true;
                        swan.push({nextY, nextX});
                    } else if (lake[nextY][nextX] == 'L' && !visited[nextY][nextX]) {
                        cout << time << "\n";
                        return 0;
                    }
                }
            }
        }

        // ≥Ï¿Ã±‚
        time++;
        int waterSize = water.size();
        while(waterSize--) {
            pair<int, int> cur = water.front(); water.pop();

            for (pair<int, int> d : dir) {
                int nextY = cur.first + d.first;
                int nextX = cur.second + d.second;
                if (visited[cur.first][cur.second]) {
                    swan.push({cur.first, cur.second});
                }

                if (isIn(nextY, nextX)) {
                    if (lake[nextY][nextX] == 'X') {
                        lake[nextY][nextX] = '.';
                        water.push({nextY, nextX});
                    }
                }
            }
        }
    }
}

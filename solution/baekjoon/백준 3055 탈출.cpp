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
char forest[60][60];
bool visited[60][60];

int r, c;

bool isIn(int y, int x) {
    return (y < r && r >= 0 && x < c && x >= 0);
}

int main() {

    cin >> r >> c;

    queue<pair<int, int>> hedgehog;
    queue<pair<int, int>> water;
    pair<int, int> cave;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> forest[i][j];

            if (forest[i][j] == '*')
                water.push({i, j});
            else if (forest[i][j] == 'S') {
                hedgehog.push({i, j});
                visited[i][j] = true;
            }
            else if (forest[i][j] == 'D')
                cave = {i, j};
        }
    }

    int time = 0;
    while(true) {
        // 물 이동
        int waterSize = water.size();
        while (waterSize--) {
            pair<int, int> cur = water.front();
            water.pop();

            for (auto &i : dir) {
                int nextY = cur.first + i.first;
                int nextX = cur.second + i.second;

                if (isIn(nextY, nextX)) {
                    if (forest[nextY][nextX] == '.' || forest[nextY][nextX] == 'S') {
                        forest[nextY][nextX] = '*';
                        water.push({nextY, nextX});
                    }
                }
            }
        }

        // 고슴도치 이동
        int hedgehogSize = hedgehog.size();
        if (hedgehogSize == 0) {
            cout << "KAKTUS\n";
            return 0;
        }
        time++;
        while (hedgehogSize--) {
            pair<int, int> cur = hedgehog.front();
            hedgehog.pop();

            for (auto &i : dir) {
                int nextY = cur.first + i.first;
                int nextX = cur.second + i.second;

                if (isIn(nextY, nextX) && !visited[nextY][nextX]) {
                    if (forest[nextY][nextX] == '.') {
                        hedgehog.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                    } else if (forest[nextY][nextX] == 'D') {
                        cout << time << "\n";
                        return 0;
                    }
                }
            }
        }
    }
}

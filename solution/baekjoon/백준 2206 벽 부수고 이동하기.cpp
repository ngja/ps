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
char world[1001][1001];
bool zeroVisited[1001][1001];
bool oneVisited[1001][1001];
int dist[1001][1001];
vector<pair<int, int>> dirs = {{-1, 0},
                               {0,  1},
                               {1,  0},
                               {0,  -1}};

bool isIn(int y, int x) {
    return (y >= 1) && (x >= 1) && (y <= n) && (x <= m);
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> world[i][j];
        }
    }

    queue<tuple<int, int, int, int>> q; // y, x, ºÎ¼û, °Å¸®
    q.push(make_tuple(1, 1, 0, 1));
    zeroVisited[1][1] = true;
    oneVisited[1][1] = true;
    dist[1][1] = 1;

    while (!q.empty()) {
        int y, x, broken, d;
        tie(y, x, broken, d) = q.front();
        q.pop();

        for (pair<int, int> dir : dirs) {
            int nextY = y + dir.first;
            int nextX = x + dir.second;

            if (isIn(nextY, nextX)) {
                if (world[nextY][nextX] == '0') {
                    if (broken == 0) {
                        if (!zeroVisited[nextY][nextX]) {
                            zeroVisited[nextY][nextX] = true;
                            q.push(make_tuple(nextY, nextX, 0, d + 1));
                            if (dist[nextY][nextX] == 0)
                                dist[nextY][nextX] = d + 1;
                        }
                    } else if (broken == 1) {
                        if (!oneVisited[nextY][nextX]) {
                            oneVisited[nextY][nextX] = true;
                            q.push(make_tuple(nextY, nextX, 1, d + 1));
                            if (dist[nextY][nextX] == 0)
                                dist[nextY][nextX] = d + 1;
                        }
                    }
                } else if (world[nextY][nextX] == '1') {
                    if (broken == 0) {
                        if (!oneVisited[nextY][nextX]) {
                            oneVisited[nextY][nextX] = true;
                            q.push(make_tuple(nextY, nextX, 1, d + 1));
                            dist[nextY][nextX] = d + 1;
                        }
                    }
                }
            }
        }
    }

    if (dist[n][m] == 0)
        cout << "-1\n";
    else
        cout << dist[n][m] << "\n";

    return 0;
}

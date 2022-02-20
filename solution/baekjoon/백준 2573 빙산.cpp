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
int arctic[301][301];
bool visited[301][301];
int r, c;

bool isIn(int y, int x) {
    return (y < r && r >= 0 && x < c && x >= 0);
}

int main() {
    cin >> r >> c;

    queue<pair<int, int>> iceberg;
    queue<tuple<int, int, int>> meltJob;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arctic[i][j];
            if (arctic[i][j] != 0)
                iceberg.push({i, j});
        }
    }

    int time = 0;
    while(true) {
        // ³ìÀ» ºù»ê ±¸ÇÏ±â
        while(!iceberg.empty()) {
            pair<int, int> cur = iceberg.front(); iceberg.pop();

            int meltCount = 0;
            for (pair<int, int> d : dir) {
                int nextY = cur.first + d.first;
                int nextX = cur.second + d.second;

                if (isIn(nextY, nextX)) {
                    if (arctic[nextY][nextX] == 0)
                        meltCount++;
                }
            }

            meltJob.push({cur.first, cur.second, meltCount});
        }

        // ³ìÀÌ°í ³²Àº ºù»ê ³Ö±â
        time++;
        while(!meltJob.empty()) {
            tuple<int, int, int> cur = meltJob.front(); meltJob.pop();
            int y = get<0>(cur);
            int x = get<1>(cur);
            int meltAmount = get<2>(cur);
            arctic[y][x] -= meltAmount;
            if (arctic[y][x] < 0)
                arctic[y][x] = 0;
            if (arctic[y][x] != 0)
                iceberg.push({y, x});
        }

        if  (iceberg.empty()) {
            cout << 0 << "\n";
            return 0;
        }

        // ºÐ¸® È®ÀÎ
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                visited[i][j] = false;
        queue<pair<int, int>> check;
        check.push(iceberg.front());
        int iceCount = 0;
        visited[check.front().first][check.front().second] = true;
        while(!check.empty()) {
            pair<int, int> cur = check.front(); check.pop();
            iceCount++;

            for (pair<int, int> d : dir) {
                int nextY = cur.first + d.first;
                int nextX = cur.second + d.second;

                if (isIn(nextY, nextX) && arctic[nextY][nextX] != 0 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    check.push({nextY, nextX});
                }
            }
        }

        if (iceCount != iceberg.size()) {
            cout << time << "\n";
            return 0;
        }
    }
}

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

const int INF = ~(1 << 31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int water[25][25];
int n;
pair<int, int> babySharkPos;
int babySharkSize = 2;
int babySharkXp = 0;
vector<pair<int, int>> dirs = {{-1, 0},
                               {0,  -1},
                               {0,  1},
                               {1,  0}};

int manhattanDist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

bool isIn(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < n) && (x < n);
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> water[i][j];
            if (water[i][j] == 9) {
                babySharkPos = {i, j};
                water[i][j] = 0;
            }
        }
    }

    int ans = 0;

    while (true) {

        bool visited[25][25] = {false,};
        bool isEat = false;

        queue<pair<int, int>> q;
        q.push(babySharkPos);
        visited[babySharkPos.first][babySharkPos.second] = true;
        int dist = 0;

        while (!q.empty()) {
            // 대상 추려내기
            vector<pair<int, int>> targetPositionList;
            while (!q.empty()) {
                targetPositionList.push_back(q.front());
                q.pop();
            }

            // 대상 정렬
            sort(targetPositionList.begin(), targetPositionList.end());

            // 대상 확인
            for (pair<int, int> targetPosition : targetPositionList) {
                int curY = targetPosition.first;
                int curX = targetPosition.second;

                if (water[curY][curX] != 0 && water[curY][curX] < babySharkSize) {
                    // EAT
                    ans += dist;
                    isEat = true;
                    babySharkXp++;
                    if (babySharkXp >= babySharkSize) {
                        babySharkSize++;
                        babySharkXp = 0; // ?
                    }
                    babySharkPos = {curY, curX};
                    water[curY][curX] = 0;
                    break;
                } else {
                    for (pair<int, int> dir : dirs) {
                        int nextY = curY + dir.first;
                        int nextX = curX + dir.second;
                        if (isIn(nextY, nextX) && !visited[nextY][nextX] && babySharkSize >= water[nextY][nextX]) {
                            visited[nextY][nextX] = true;
                            q.push({nextY, nextX});
                        }
                    }
                }
            }

            dist++;

            if (isEat)
                break;
        }

        if (isEat)
            continue;
        else
            break;
    }


    cout << ans << "\n";

    return 0;
}

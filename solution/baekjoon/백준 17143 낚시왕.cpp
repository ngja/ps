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

struct Shark {
    int y, x;
    int speed;
    int dir;
    int size;
    bool die;
};

int n, m, k;
int fishingHole[101][101];
int manPosition;
vector<Shark> sharks;

vector<pair<int, int>> dirs = {
        {0,  0},
        {-1, 0}, // 위 1
        {1,  0}, // 아래 2
        {0,  1}, // 오른쪽 3
        {0,  -1}  // 왼쪽 4
};

int realMove(Shark shark) {

    if (shark.speed == 0) {
        return 0;
    }

    if (shark.dir == 1 || shark.dir == 2) {
        return (shark.speed % (2*n-2));
    } else {
        return (shark.speed % (2*m-2));
    }
}

int isIn(int y, int x) {
    return (y >= 1) && (y <= n) && (x >= 1) && (x <= m);
}

int changeDir(int d) {
    if (d == 1)
        return 2;
    else if (d == 2)
        return 1;
    else if (d == 3)
        return 4;
    else
        return 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fishingHole[i][j] = -1;
        }
    }

    for (int i = 0; i < k; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark shark = {r, c, s, d, z, false};
        sharks.push_back(shark);
        fishingHole[r][c] = i;
    }

    int ans = 0;
    while (true) {
        manPosition++; // 낚시왕 이동

        if (manPosition > m) break;

        for (int i = 1; i <= n; ++i) { // 상어 잡기
            if (fishingHole[i][manPosition] >= 0) {
                int sharkIndex = fishingHole[i][manPosition];
                ans += sharks[sharkIndex].size;
                sharks[sharkIndex].die = true;
                fishingHole[i][manPosition] = -1;
                break;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                fishingHole[i][j] = -1;
            }
        }

        // 상어 이동
        for (int i = 0; i < k; ++i) {
            if (sharks[i].die) continue;

            int realMoveCount = realMove(sharks[i]);

            for (int j = 0; j < realMoveCount; ++j) {
                int nextY = sharks[i].y + dirs[sharks[i].dir].first;
                int nextX = sharks[i].x + dirs[sharks[i].dir].second;

                if (isIn(nextY, nextX)) {
                    sharks[i].y = nextY;
                    sharks[i].x = nextX;
                } else {
                    sharks[i].dir = changeDir(sharks[i].dir);
                    sharks[i].y = sharks[i].y + dirs[sharks[i].dir].first;
                    sharks[i].x = sharks[i].x + dirs[sharks[i].dir].second;
                }
            }

            if (fishingHole[sharks[i].y][sharks[i].x] == -1) {
                fishingHole[sharks[i].y][sharks[i].x] = i;
            } else {
                int beforeShark = fishingHole[sharks[i].y][sharks[i].x];
                if (sharks[i].size > sharks[beforeShark].size) {
                    fishingHole[sharks[i].y][sharks[i].x] = i;
                    sharks[beforeShark].die = true;
                } else {
                    sharks[i].die = true;
                }
            }
        }
    }

    cout << ans << "\n";


    return 0;
}
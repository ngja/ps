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
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int r, c, t;
int room[55][55];
pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
pair<int, int> updirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
pair<int, int> downdirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isIn(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < r) && (x < c);
}

int main() {

    cin >> r >> c >> t;

    pair<int, int> upAirClean = {-1, -1};
    pair<int, int> downAirClean = {-1, -1};

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                if (upAirClean.first == -1) {
                    upAirClean = {i, j};
                } else {
                    downAirClean = {i, j};
                }
            }
        }
    }

    while(t--) {
        // 먼지 확산
        vector<pair<int, int>> dustPos;
        vector<int> dustAmount;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (room[i][j] > 0) {
                    int totalDiffusedAmount = 0;
                    for (auto & dir : dirs) {
                        int nextY = i + dir.first;
                        int nextX = j + dir.second;

                        if (isIn(nextY, nextX) && (room[nextY][nextX] != -1)) {
                            int diffusedAmount = room[i][j] / 5;
                            if (diffusedAmount != 0) {
                                dustPos.emplace_back(nextY, nextX);
                                dustAmount.push_back(diffusedAmount);
                                totalDiffusedAmount += diffusedAmount;
                            }
                        }
                    }
                    dustPos.emplace_back(i, j);
                    dustAmount.push_back(-totalDiffusedAmount);
                }
            }
        }
        // 실제 적용
        for (int i = 0; i < dustPos.size(); i++) {
            int targetY = dustPos[i].first;
            int targetX = dustPos[i].second;
            int amount = dustAmount[i];

            room[targetY][targetX] += amount;
        }

        // 위 공기청정기 가동
        pair<int, int> tempAirPos = {upAirClean.first - 1, upAirClean.second};
        int dirIdx = 0;
        while(true) {
            if (tempAirPos.first == upAirClean.first && tempAirPos.second == upAirClean.second)
                break;

            if (isIn(tempAirPos.first + updirs[dirIdx].first, tempAirPos.second + updirs[dirIdx].second) && (tempAirPos.first + updirs[dirIdx].first < upAirClean.first + 1)) {
                if (room[tempAirPos.first + updirs[dirIdx].first][tempAirPos.second + updirs[dirIdx].second] == -1) {
                    room[tempAirPos.first][tempAirPos.second] = 0;
                    break;
                } else {
                    room[tempAirPos.first][tempAirPos.second] = room[tempAirPos.first + updirs[dirIdx].first][tempAirPos.second + updirs[dirIdx].second];
                    tempAirPos.first = tempAirPos.first + updirs[dirIdx].first;
                    tempAirPos.second = tempAirPos.second + updirs[dirIdx].second;
                }
            } else {
                dirIdx++;
            }
        }

        // 아래 공기청정기 가동
        tempAirPos = {downAirClean.first + 1, downAirClean.second};
        dirIdx = 0;
        while(true) {
            if (tempAirPos.first == upAirClean.first && tempAirPos.second == upAirClean.second)
                break;

            if (isIn(tempAirPos.first + downdirs[dirIdx].first, tempAirPos.second + downdirs[dirIdx].second) && (tempAirPos.first + downdirs[dirIdx].first >= downAirClean.first)) {
                if (room[tempAirPos.first + downdirs[dirIdx].first][tempAirPos.second + downdirs[dirIdx].second] == -1) {
                    room[tempAirPos.first][tempAirPos.second] = 0;
                    break;
                } else {
                    room[tempAirPos.first][tempAirPos.second] = room[tempAirPos.first + downdirs[dirIdx].first][tempAirPos.second + downdirs[dirIdx].second];
                    tempAirPos.first = tempAirPos.first + downdirs[dirIdx].first;
                    tempAirPos.second = tempAirPos.second + downdirs[dirIdx].second;
                }
            } else {
                dirIdx++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (room[i][j] > 0) {
                ans += room[i][j];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

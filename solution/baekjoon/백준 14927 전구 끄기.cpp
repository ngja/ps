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
const ll LL_INF = 10000000000LL;
const int INF = 2000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

int original[20][20];
int led[20][20];
int n;

vector<pair<int, int>> dirs = {
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0}
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < n);
}

void turnOff(int y, int x) {

    led[y][x] = 1 ^ led[y][x];

    for (pair<int, int> k : dirs) {
        int nextY = y + k.first;
        int nextX = x + k.second;
        if (isIn(nextY, nextX)) {
            led[nextY][nextX] = 1 ^ led[nextY][nextX];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> original[i][j];
        }
    }

    int ans = INF;
    bool possible = true;

    for (int c = 0; c < (1 << n); c++) {
        // 1인거 버튼을 누른다고 생각
        possible = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                led[i][j] = original[i][j];
            }
        }

        int turnOffCount = 0;
        for (int d = 0; d < n; d++) {
            if (c & (1 << d)) {
                turnOff(0, d);
                turnOffCount++;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (led[i - 1][j] == 1) {
                    turnOff(i, j);
                    turnOffCount++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (led[n-1][i] == 1) {
                possible = false;
                break;
            }
        }

        if (possible) {
            ans = min(ans, turnOffCount);
        }
    }

    if (ans == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
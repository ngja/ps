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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

vector<vector<pair<int, int>>> tetrises = {
        {{1, 0}, {2, 0}, {3, 0}},
        {{0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {0, 1}, {1, 1}},
        {{1, 0}, {2, 0}, {2, 1}},
        {{1, 0}, {0, 1}, {0, 2}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 1}, {0, 2}, {-1, 2}},
        {{1, 0}, {2, 0}, {2, -1}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{1, 0}, {0, 1}, {2, 0}},
        {{0, 1}, {0, 2}, {1, 2}},
        {{1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {-1, 1}, {-1, 2}},
        {{1, 0}, {1, -1}, {2, -1}},
        {{0, 1}, {1, 1}, {1, 2}},
        {{1, 0}, {1, -1}, {1, 1}},
        {{1, 0}, {2, 0}, {1, 1}},
        {{0, 1}, {1, 1}, {0, 2}},
        {{0, 1}, {1, 1}, {-1, 1}},
};

int n, m;
int world[550][550];

bool isIn(int y, int x, int tetrisIndex) {
    vector<pair<int, int>> &block = tetrises[tetrisIndex];

    return (y+block[0].first <= n) && (y+block[0].first > 0)
    && (y+block[1].first <= n) && (y+block[1].first > 0)
    && (y+block[2].first <= n) && (y+block[2].first > 0)
    && (x+block[0].second <= m) && (x+block[0].second > 0)
    && (x+block[1].second <= m) && (x+block[1].second > 0)
    && (x+block[2].second <= m) && (x+block[2].second > 0);
}
        

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> world[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            for (int k = 0; k < tetrises.size(); k++) {
                if (isIn(i, j, k)) {
                    int tempSum = world[i][j]
                            + world[i+tetrises[k][0].first][j+tetrises[k][0].second]
                            + world[i+tetrises[k][1].first][j+tetrises[k][1].second]
                            + world[i+tetrises[k][2].first][j+tetrises[k][2].second];

                    if (ans < tempSum)
                        ans = tempSum;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

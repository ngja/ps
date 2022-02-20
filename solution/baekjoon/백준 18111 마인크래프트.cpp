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

int mine[505][505];
int n, m, b;

int main() {

    int minHeight = INF;
    int maxHeight = 0;

    cin >> n >> m >> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mine[i][j];

            minHeight = min(minHeight, mine[i][j]);
            maxHeight = max(maxHeight, mine[i][j]);
        }
    }


    int ansTime = INF;
    int ansHeight = maxHeight;
    for (int h = maxHeight; h >= minHeight; h--) {
        int temp = 0;
        int fillCount = 0;
        int lightenCount = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int delta = (h - mine[i][j]);

                if (delta < 0)
                    lightenCount -= delta;
                else if (delta > 0)
                    fillCount += delta;

                temp += delta;
            }
        }

        if (temp <= b) {
            int totalTime = 2 * lightenCount + fillCount;
            if (ansTime > totalTime) {
                ansTime = totalTime;
                ansHeight = h;
            }
        }
    }

    cout << ansTime << " " << ansHeight << "\n";

    return 0;
}

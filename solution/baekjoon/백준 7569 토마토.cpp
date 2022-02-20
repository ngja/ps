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

int n, m, h;
int tomato[101][101][101];
vector<tuple<int, int, int>> dir = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {-1, 0, 0},
        {0, -1, 0},
        {0, 0, -1}
};

bool isIn(int y, int x, int z) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < m) && (z >= 0) && (z < h);
}

int main() {

    cin >> m >> n >> h;

    int tomatoCount = 0;
    int ripenTomatoCount = 0;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> tomato[j][k][i];
                if (tomato[j][k][i] == 1)
                    q.push(make_tuple(j, k, i));
                else if (tomato[j][k][i] == 0)
                    tomatoCount++;
            }
        }
    }

    if (tomatoCount == 0) {
        cout << "0\n";
        return 0;
    }

    int day = 0;
    while(true) {
        int ripenTomato = q.size();
        while(ripenTomato--) {
            tuple<int, int, int> cur = q.front(); q.pop();
            int y = get<0>(cur);
            int x = get<1>(cur);
            int z = get<2>(cur);

            for (auto k : dir) {
                int nextY = y+get<0>(k);
                int nextX = x+get<1>(k);
                int nextZ = z+get<2>(k);
                if (isIn(nextY, nextX, nextZ)) {
                    if (tomato[nextY][nextX][nextZ] == 0) {
                        tomato[nextY][nextX][nextZ] = 1;
                        ripenTomatoCount++;
                        q.push(make_tuple(nextY, nextX, nextZ));
                    }
                }
            }
        }

        if (q.empty())
            break;

        day++;
    }

    if (ripenTomatoCount == tomatoCount) {
        cout << day << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}

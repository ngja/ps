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

const ll MOD = 1'000'000'007LL;
const int INF = 2'000'000'000;
const ll LL_INF = 10'000'000'000LL;

int n;
bool visit[202][202];

vector<pair<int, int>> dirs = {
        {-2, -1},
        {-2, +1},
        {0, -2},
        {0, +2},
        {2, -1},
        {2, 1}
};

bool isIn(int y, int x) {
    return (y >= 0) && (x >= 0) && (y < n) && (x < n);
}

struct DeathNight {
    int r;
    int c;
    int numberOfMoves;
};

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int r1, c1, r2, c2;

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    visit[r1][c1] = true;
    queue<DeathNight> q;
    q.push({r1, c1, 0});

    int ans = 0;
    while (!q.empty()) {
        DeathNight now = q.front();
        q.pop();

        if (now.r == r2 && now.c == c2) {
            cout << now.numberOfMoves << "\n";
            return 0;
        }

        for (pair<int, int> dir : dirs) {
            int nextR = now.r + dir.first;
            int nextC = now.c + dir.second;

            if (!isIn(nextR, nextC))
                continue;
            if (visit[nextR][nextC])
                continue;

            visit[nextR][nextC] = true;
            q.push({nextR, nextC, now.numberOfMoves + 1});
        }
    }

    cout << -1 << "\n";

    return 0;
}
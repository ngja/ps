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

int n, m;
bool visited[505][505];
int paper[505][505];
vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};
int paintCounter = 0;
int largeSize = 0;

bool isOut(int x, int y) {
    return (x < 0) || (x >= n) || (y < 0) || (y >= m);
}

void bfs(int x, int y) {
    paintCounter++;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    int size = 0;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        visited[now.first][now.second] = true;
        size++;

        for (pair<int, int> dir : dirs) {
            pair<int, int> next = {now.first + dir.first, now.second + dir.second};
            if (isOut(next.first, next.second))
                continue;
            if (visited[next.first][next.second])
                continue;
            if (paper[next.first][next.second] == 0)
                continue;
            visited[next.first][next.second] = true;
            q.push(next);
        }
    }

    if (largeSize < size) {
        largeSize = size;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    // bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && paper[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << paintCounter << "\n" << largeSize << "\n";
}
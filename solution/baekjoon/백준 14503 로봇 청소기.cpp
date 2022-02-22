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
int room[55][55];
bool visit[55][55];
vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Robot {
    pair<int, int> pos;
    int dir; // 0 북, 1 동, 2 남, 3 서
};

int turnLeft(int d) {
    return (d + 3) % 4;
}

int turnBack(int d) {
    return (d + 2) % 4;
}

bool isOut(int y, int x) {
    return (y >= n || y < 0 || x >= m || x < 0);
}

int clean(Robot &r) {

    int cleanCount = 0;

    bool cleaned = true;
    while(true) {

        // 1.
        if (cleaned) {
            visit[r.pos.first][r.pos.second] = true;
            room[r.pos.first][r.pos.second] = 2;
            cleanCount += 1;
        }
        
        cleaned = false;
        // 북 -> 서 -> 남 -> 동 -> 북
        for (int i = 0; i < 4; i++) {

            int nextDir = turnLeft(r.dir);
            r.dir = nextDir;
            pair<int, int> nextDirs = dirs[nextDir];

            int nextY = r.pos.first + nextDirs.first;
            int nextX = r.pos.second + nextDirs.second;

            if (isOut(nextY, nextX))
                continue;

            if (visit[nextY][nextX])
                continue;

            if (room[nextY][nextX] == 1)
                continue;

            // 2. a.
            cleaned = true;
            r.pos.first = nextY;
            r.pos.second = nextX;
            break;
        }
        
        if (cleaned) {
            continue;
        }

        int backDir = turnBack(r.dir);
        pair<int, int> backDirs = dirs[backDir];
        
        int backY = r.pos.first + backDirs.first;
        int backX = r.pos.second + backDirs.second;
        
        if (isOut(backY, backX)) 
            break;

        if (room[backY][backX] == 1)
            break;
        
        r.pos.first = backY;
        r.pos.second = backX;
    }
    
    return cleanCount;
}

int main() {
    
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    Robot robot = {{r, c}, d};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }

    int ans = clean(robot);

    cout << ans << "\n";
    
    return 0;
}
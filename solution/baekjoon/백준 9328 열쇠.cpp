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

int ans = 0;
int h, w;

pair<int, int> dirs[4] = {
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0}
};

bool isIn(int y, int x) {
    return (y >= 0) && (y < h) && (x >= 0) && (x < w);
}

bool canMove(char c) {
    return (c == '$') || (c == '.') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isKey(char c) {
    return (c >= 'a' && c <= 'z');
}

bool isDoc(char c) {
    return (c == '$');
}

bool isDoor(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool canOpen(char c, int keys) {
    char needKey = tolower(c, locale());
    return (keys >> (needKey - 'a')) & 1;
}

void initialSetting(int y, int x, char world[101][101], bool visited[101][101], queue<pair<int, int>>& spaceQueue, queue<pair<int, int>>& doorQueue, int& keyChain) {
    if (visited[y][x])
        return;
    if (!canMove(world[y][x]))
        return;

    visited[y][x] = true;

    if (isDoc(world[y][x])) {
        ans++;
        spaceQueue.push({y, x});
    } else if (isKey(world[y][x])) {
        keyChain |= (1 << (world[y][x] - 'a'));
        spaceQueue.push({y, x});
    } else if (isDoor(world[y][x])) {
        if (canOpen(world[y][x], keyChain)) {
            spaceQueue.push({y, x});
        } else {
            doorQueue.push({y, x});
        }
    } else {
        spaceQueue.push({y, x});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> h >> w;

        char world[101][101];
        bool visited[101][101];
        int keyChain = 0;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> world[i][j];
                visited[i][j] = false;
            }
        }

        string keyInput;
        cin >> keyInput;

        if (keyInput == "0") {
            keyChain = 0;
        } else {
            for (char k : keyInput) {
                keyChain |= (1 << (k - 'a'));
            }
        }

        queue<pair<int, int>> spaceQueue;
        queue<pair<int, int>> doorQueue;

        // 가투리 시작 가능한 곳 넣기
        for (int i = 0; i < h; ++i) { // 좌, 우
            initialSetting(i, 0, world, visited, spaceQueue, doorQueue, keyChain);
            initialSetting(i, w-1, world, visited, spaceQueue, doorQueue, keyChain);
        }
        for (int i = 0; i < w; ++i) { // 상, 하
            initialSetting(0, i, world, visited, spaceQueue, doorQueue, keyChain);
            initialSetting(h-1, i, world, visited, spaceQueue, doorQueue, keyChain);
        }

        while (true) {
            while (!spaceQueue.empty()) {
                pair<int, int> cur = spaceQueue.front();
                spaceQueue.pop();

                for (pair<int, int> dir: dirs) {
                    int nextY = cur.first + dir.first;
                    int nextX = cur.second + dir.second;

                    if (!isIn(nextY, nextX))
                        continue;
                    if (visited[nextY][nextX])
                        continue;
                    if (world[nextY][nextX] == '*')
                        continue;

                    visited[nextY][nextX] = true;

                    if (isDoc(world[nextY][nextX])) {
                        ans++;
                        spaceQueue.push({nextY, nextX});
                    } else if (isKey(world[nextY][nextX])) {
                        keyChain |= (1 << (world[nextY][nextX] - 'a'));
                        spaceQueue.push({nextY, nextX});
                    } else if (isDoor(world[nextY][nextX])) {
                        if (canOpen(world[nextY][nextX], keyChain)) {
                            spaceQueue.push({nextY, nextX});
                        } else {
                            doorQueue.push({nextY, nextX});
                        }
                    } else {
                        spaceQueue.push({nextY, nextX});
                    }
                }
            }

            int doorQueueSize = doorQueue.size();

            for (int i = 0; i < doorQueueSize; ++i) {
                pair<int, int> doorPos = doorQueue.front();
                doorQueue.pop();

                if (canOpen(world[doorPos.first][doorPos.second], keyChain)) {
                    spaceQueue.push({doorPos.first, doorPos.second});
                } else {
                    doorQueue.push({doorPos.first, doorPos.second});
                }
            }

            if (doorQueueSize == doorQueue.size()) {
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
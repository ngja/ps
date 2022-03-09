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

struct State {
    int smileCount;
    int clipboard;
    int operationTime;
};

int minimumTime[1500][1500];
bool visit[1500][1500]; // [smileCount][clipboard]

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int n;
    int clipboard = 1;
    cin >> n;

    queue<State> q;
    q.push({1, 0, 0});
    
    while (!q.empty()) {
        State state = q.front();
        q.pop();

        visit[state.smileCount][state.clipboard] = true;
        int nextOperationTime = state.operationTime + 1;

        if (state.smileCount == n) {
            cout << state.operationTime << "\n";
            break;
        }

        // 클립 보드 저장
        int nextClipboard = state.smileCount;
        if (nextClipboard <= 1024) {
            if (!visit[state.smileCount][nextClipboard]) {
                q.push({state.smileCount, nextClipboard, nextOperationTime});
            }
        }

        // 붙여넣기
        if (state.clipboard != 0) {
            int nextSmileCount = state.smileCount + state.clipboard;
            if (nextSmileCount <= 1024) {
                if (!visit[nextSmileCount][state.clipboard]) {
                    q.push({nextSmileCount, state.clipboard, nextOperationTime});
                }
            }
        }

        // 이모티콘 삭제
        if (state.smileCount >= 1) {
            int nextSmileCount = state.smileCount - 1;
            if (!visit[nextSmileCount][state.clipboard]) {
                q.push({nextSmileCount, state.clipboard, nextOperationTime});
            }
        }
    }
    
    

    return 0;
}
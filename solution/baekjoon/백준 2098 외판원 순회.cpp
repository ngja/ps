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
typedef pair<int, int> pii;

using namespace std;

int n;
int dist[20][20];
int dp[20][1 << 20]; // dp[i][j] 현재 위치 i이고 방문한 조건이 j일 때 최소 거리

int tsp(int current, int visited) {

    // 모든 곳을 다 방문한 상태
    if (visited == (1<<n)-1)
        return dist[current][0] == 0 ? INF : dist[current][0];

    if (dp[current][visited] != -1)
        return dp[current][visited];

    // 방문하지 않은 곳 방문하기
    dp[current][visited] = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1<<i)) continue;
        if (dist[current][i] == 0) continue;
        dp[current][visited] = min(dp[current][visited], tsp(i, (visited | (1<<i))) + dist[current][i]);
    }

    return dp[current][visited];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << "\n";



    return 0;
}

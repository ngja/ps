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
typedef pair<int, int> pi;

int n, m, r; // 지역수, 수색범위, 길수
int item[101];

int main() {

    cin >> n >> m >> r;

    for (int i = 1; i <= n; ++i) {
        cin >> item[i];
    }

    vector<vector<pair<int, int>>> world(n+1); // {정점, 거리}
    for (int i = 0; i < r; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        world[a].push_back({b, d});
        world[b].push_back({a, d});
    }

    int ans = 0;
    // 1번 지역부터 n번 지역까지 다익스트라
    for (int i = 1; i <= n; ++i) {
        int tempAns = 0;
        priority_queue<pair<int, int>> q; // {-거리, 정점}
        vector<int> dist;
        dist.assign(n+1, INF);
        vector<bool> visited;
        visited.assign(n+1, false);

        q.push({0, i});
        dist[i] = 0;
        while(!q.empty()) {
            int from = q.top().second; q.pop();
            if (visited[from]) continue;
            visited[from] = true;
            for (pair<int, int> next : world[from]) {
                int to = next.first, len = next.second;
                if (dist[to] > dist[from] + len) {
                    dist[to] = dist[from] + len;
                    q.push({-dist[to], to});
                }
            }
        }

        for (int j = 1; j <= n; ++j) {
            if (dist[j] <= m) {
                tempAns += item[j];
            }
        }

        if (ans < tempAns) {
            ans = tempAns;
        }
    }

    cout << ans << "\n";

    return 0;
}

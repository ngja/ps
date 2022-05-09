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


const int INDEX = 52;
const int SOURCE = 0;
const int SINK = 25;
int alphabetToIndex(char alphabet) {
    if (alphabet <= 'Z') return alphabet - 'A'; // 대문자 0~25
    return alphabet - 'a' + 26; // 소문자 26~51
}

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int n;
    cin >> n;

    vector<vector<int>> graph(INDEX, vector<int>());
    vector<vector<int>> c(INDEX, vector<int>(INDEX, 0));
    vector<vector<int>> f(INDEX, vector<int>(INDEX, 0));
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        char u, v;
        int capacity;
        cin >> u >> v >> capacity;

        // 노드 연결
        int uIdx = alphabetToIndex(u);
        int vIdx = alphabetToIndex(v);
        graph[uIdx].push_back(vIdx);
        graph[vIdx].push_back(uIdx);

        c[uIdx][vIdx] += capacity;
        c[vIdx][uIdx] += capacity;
    }

    while(1) {
        vector<int> prev(INDEX, -1);
        queue<int> q;
        q.push(SOURCE);

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int next : graph[now]) {
                if (prev[next] != -1)
                    continue;

                if (c[now][next] - f[now][next] <= 0)
                    continue;

                q.push(next);
                prev[next] = now;
                if (next == SINK)
                    break;
            }

            if (prev[SINK] != -1)
                break;
        }

        if (prev[SINK] == -1)
            break;

        int flow = INF;
        for (int i = SINK; i != SOURCE; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

        for (int i = SINK; i != SOURCE; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }

        ans += flow;
    }

    cout << ans << "\n";
    return 0;
}
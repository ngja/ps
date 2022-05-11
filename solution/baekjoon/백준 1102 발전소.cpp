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

int n, p;
int cost[17][17];
int memoization[(1<<16)];
int init = 0;

// cur 형태로 발전소가 켜져 있을 때 최소 비용으로 p개 이상 켜는 수
int solution(int cur) {
    if (__builtin_popcount(cur) >= p)
        return 0;

    if (memoization[cur] != INF)
        return memoization[cur];

    // 키려고 하는 발전소 i, 켜기 위해 사용할 발전소 j
    for (int i = 0; i < n; i++) {
        if (!(cur & (1<<i))) {
            int minCost = INF;

            for (int j = 0; j < n; j++) {
                if (cur & (1<<j)) {
                    minCost = min(minCost, cost[j][i]);
                }
            }

            int next = cur | (1<<i);
            memoization[cur] = min(memoization[cur], solution(next) + minCost);
        }
    }

    return memoization[cur];
}

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }
    string onOff;
    cin >> onOff;
    for (int i = 0; i < n; ++i) {
        char c = onOff[i];
        if ('Y' == c) {
            init |= (1 << i);
        }
    }
    cin >> p;

    fill(memoization, memoization + (1<<16), INF);

    int ans = solution(init);

    if (INF == ans) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
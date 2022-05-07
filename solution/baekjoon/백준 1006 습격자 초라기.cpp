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

int n, w;
bool canCombine(int a, int b) {
    return a + b <= w;
}

void initDp(vector<int> (&dp)[3]) {
    for (auto & i : dp) {
        i.assign(n, INF);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> w;

        vector<int> area[2];
        area[0].resize(n);
        area[1].resize(n);
        for (int i = 0; i < n; ++i)
            cin >> area[0][i];
        for (int i = 0; i < n; ++i)
            cin >> area[1][i];

        // dp[0][] = 끝이 일자인 형태
        // dp[1][] = 끝이 위가 한 칸 튀어 나온 형태
        // dp[2][] = 끝이 아래가 하 칸 튀어 나온 형태
        vector<int> dp[3];
        initDp(dp);

        // dp[0][] 점화식
        // 1. dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1)
        // 2. if (area[0][i]+area[1][i] <= w) dp[0][i] = min(dp[0][i], dp[0][i-1]+1)
        // 3. if (area[0][i-1]+area[0][i] <= w && area[1][i-1]+area[1][i] <= w) dp[0][i] = min(dp[0][i], dp[0][i-2]+2)

        // dp[1][] 점화식
        // 1. dp[1][i] = dp[0][i]+1
        // 2. if (area[0][i]+area[0][i+1] <= w) dp[1][i] = min(dp[1][i], dp[2][i-1]+1)

        // dp[2][] 점화식
        // 1. dp[2][i] = dp[0][i]+1
        // 2. if (area[1][i]+area[1][i+1] <= w) dp[2][i] = min(dp[2][i], dp[1][i-1]+1)

        // 초깃값 세팅
        // 0, N-1 열 연결이 없는 경우
        if (canCombine(area[0][0], area[1][0]))
            dp[0][0] = 1;
        else
            dp[0][0] = 2;

        if (n == 1) {
            cout << dp[0][0] << "\n";
            continue;
        }

        dp[1][0] = dp[0][0] + 1;
        if (canCombine(area[0][0], area[0][1]))
            dp[1][0] = 2;
        dp[2][0] = dp[0][0] + 1;
        if (canCombine(area[1][0], area[1][1]))
            dp[2][0] = 2;

        // dp 계산
        for (int i = 1; i < n; i++) {
            dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1);
            if (canCombine(area[0][i], area[1][i]))
                dp[0][i] = min(dp[0][i], dp[0][i-1]+1);
            if (canCombine(area[0][i-1], area[0][i]) && canCombine(area[1][i-1], area[1][i])) {
                if (i >= 2)
                    dp[0][i] = min(dp[0][i], dp[0][i-2]+2);
                else
                    dp[0][i] = 2;
            }

            dp[1][i] = dp[0][i]+1;
            if (i+1 < n) {
                if (canCombine(area[0][i], area[0][i+1]))
                    dp[1][i] = min(dp[1][i], dp[2][i-1]+1);
            }

            dp[2][i] = dp[0][i]+1;
            if (i+1 < n) {
                if (canCombine(area[1][i], area[1][i+1]))
                    dp[2][i] = min(dp[2][i], dp[1][i-1]+1);
            }
        }

        int ans = dp[0][n-1];

        // 0, N-1 열이 연결된 경우
        // 1. 위만 연결 된 경우
        if (canCombine(area[0][0], area[0][n-1])) {
            initDp(dp);
            dp[0][0] = 1;
            dp[1][0] = 2;
            if (canCombine(area[1][0], area[1][1]))
                dp[2][0] = 1;
            else
                dp[2][0] = 2;

            for (int i = 1; i < n - 1; i++) {
                dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1);
                if (canCombine(area[0][i], area[1][i]))
                    dp[0][i] = min(dp[0][i], dp[0][i-1]+1);
                if (i >= 2) {
                    if (canCombine(area[0][i-1], area[0][i]) && canCombine(area[1][i-1], area[1][i]))
                        dp[0][i] = min(dp[0][i], dp[0][i-2]+2);
                }

                dp[1][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[0][i], area[0][i+1]))
                        dp[1][i] = min(dp[1][i], dp[2][i-1]+1);
                }

                dp[2][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[1][i], area[1][i+1]))
                        dp[2][i] = min(dp[2][i], dp[1][i-1]+1);
                }
            }

            ans = min(ans, dp[2][n-2] + 1);
        }

        // 2. 아래만 연결 된 경우
        if (canCombine(area[1][0], area[1][n-1])) {
            initDp(dp);
            dp[0][0] = 1;
            dp[2][0] = 2;
            if (canCombine(area[0][0], area[0][1]))
                dp[1][0] = 1;
            else
                dp[1][0] = 2;

            for (int i = 1; i < n - 1; i++) {
                dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1);
                if (canCombine(area[0][i], area[1][i]))
                    dp[0][i] = min(dp[0][i], dp[0][i-1]+1);
                if (i >= 2) {
                    if (canCombine(area[0][i-1], area[0][i]) && canCombine(area[1][i-1], area[1][i]))
                        dp[0][i] = min(dp[0][i], dp[0][i-2]+2);
                }

                dp[1][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[0][i], area[0][i+1]))
                        dp[1][i] = min(dp[1][i], dp[2][i-1]+1);
                }

                dp[2][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[1][i], area[1][i+1]))
                        dp[2][i] = min(dp[2][i], dp[1][i-1]+1);
                }
            }

            ans = min(ans, dp[1][n-2] + 1);
        }

        // 3. 위, 아래 다 연결 된 경우
        if (canCombine(area[0][0], area[0][n-1]) && canCombine(area[1][0], area[1][n-1])) {
            initDp(dp);
            dp[0][0] = 0;
            dp[1][0] = 1;
            dp[2][0] = 1;

            for (int i = 1; i < n - 1; i++) {
                dp[0][i] = min(dp[1][i-1]+1, dp[2][i-1]+1);
                if (canCombine(area[0][i], area[1][i]))
                    dp[0][i] = min(dp[0][i], dp[0][i-1]+1);
                if (i >= 2) {
                    if (canCombine(area[0][i-1], area[0][i]) && canCombine(area[1][i-1], area[1][i]))
                        dp[0][i] = min(dp[0][i], dp[0][i-2]+2);
                }

                dp[1][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[0][i], area[0][i+1]))
                        dp[1][i] = min(dp[1][i], dp[2][i-1]+1);
                }

                dp[2][i] = dp[0][i]+1;
                if (i+1 < n) {
                    if (canCombine(area[1][i], area[1][i+1]))
                        dp[2][i] = min(dp[2][i], dp[1][i-1]+1);
                }
            }

            ans = min(ans, dp[0][n-2] + 2);
        }

        cout << ans << "\n";
    }

    return 0;
}
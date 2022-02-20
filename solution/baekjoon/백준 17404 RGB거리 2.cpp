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

int n;
int dp[1010][4][4]; // 1=R, 2=G, 3=B [순서][순서의 색][첫색]

struct RGB {
    int r, g, b;

    int getCost(int order) const {
        if (order == 1) {
            return r;
        } else if (order == 2) {
            return g;
        } else {
            return b;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<RGB> rgbs;
    rgbs.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> rgbs[i].r >> rgbs[i].g >> rgbs[i].b;

    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 1, 1));
    q.push(make_tuple(0, 2, 2));
    q.push(make_tuple(0, 3, 3));

    dp[0][1][1] = rgbs[0].r;
    dp[0][2][2] = rgbs[0].g;
    dp[0][3][3] = rgbs[0].b;

    while(!q.empty()){
        tuple<int, int, int> target = q.front();
        q.pop();
        int order = get<0>(target);
        int currentColor = get<1>(target);
        int firstColor = get<2>(target);

        for (int i = 1; i <= 3; i++) {
            if (currentColor == i)
                continue;

            if (dp[order + 1][i][firstColor] == 0) { // 처음 세팅하는 경우
                dp[order + 1][i][firstColor] = dp[order][currentColor][firstColor] + rgbs[order + 1].getCost(i);
                if (order + 1 < n)
                    q.push(make_tuple(order+1, i, firstColor));
            } else {
                dp[order + 1][i][firstColor] = min(dp[order + 1][i][firstColor], dp[order][currentColor][firstColor] + rgbs[order + 1].getCost(i));
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i==j)
                continue;
            ans = min(ans, dp[n-1][i][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
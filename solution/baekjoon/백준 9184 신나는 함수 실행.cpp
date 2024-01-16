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

int dp[101][101][101];

int convert(int x) {
    return x + 50;
}

int w(int x, int y, int z) {
    if (dp[convert(x)][convert(y)][convert(z)] != 0) {
        return dp[convert(x)][convert(y)][convert(z)];
    }

    if (x <= 0 || y <= 0 || z <= 0) {
        dp[convert(x)][convert(y)][convert(z)] = 1;
    } else if (x > 20 || y > 20 || z > 20) {
        dp[convert(x)][convert(y)][convert(z)] = w(20, 20, 20);
    } else if (x < y && y < z) {
        dp[convert(x)][convert(y)][convert(z)] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
    } else {
        dp[convert(x)][convert(y)][convert(z)] =
                w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
    }
    return dp[convert(x)][convert(y)][convert(z)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}
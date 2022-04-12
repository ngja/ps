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

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int n, l, r, x;
    int num[20];
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        int hard = 0;
        int easy = INF;

        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                sum += num[j];
                if (hard < num[j])
                    hard = num[j];
                if (easy > num[j])
                    easy = num[j];
            }
        }

        if (sum >= l && sum <= r) {
            if ((hard - easy) >= x) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
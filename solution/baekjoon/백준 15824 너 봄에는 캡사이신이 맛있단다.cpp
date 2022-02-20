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

const ll MOD = 1000000007LL;
const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

int n;

ll twoPower(ll power) {
    ll two = 2LL;
    ll result = 1LL;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * two) % MOD;
        }
        two = (two * two) % MOD;
        power /= 2;
    }
    return result;
}

ll plusSolution(ll num, ll power) {
    return ((num % MOD) * (twoPower(power) - 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<ll> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    ll ans = 0LL;

    for (int i = 0; i < n; ++i) {

        ll pp = ((numbers[i] % MOD) * twoPower(i)) % MOD;
        ll mm = ((numbers[i] % MOD) * twoPower(n - i - 1)) % MOD;
        ll temp = (pp - mm) % MOD;

        if (temp < 0)
            temp += MOD;

        ans += temp;
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}
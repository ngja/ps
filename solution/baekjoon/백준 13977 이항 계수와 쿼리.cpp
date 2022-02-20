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

const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

const ll MOD = 1000000007LL;
const int SIZE = 4000001;
ll fac[SIZE];
ll facinv[SIZE];
ll inv[SIZE];
int n;

ll findInv(ll a) {
    if (inv[a] > 0) return inv[a];
    return inv[a] = ((MOD - MOD / a) * findInv(MOD % a)) % MOD;
}

ll comb(ll a, ll b) {
    ll r = (fac[a] * facinv[a - b]) % MOD;
    r = (r * facinv[b]) % MOD;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = fac[1] = facinv[0] = facinv[1] = inv[1] = 1;
    for (int i = 2; i < SIZE; ++i) {
        fac[i] = (fac[i-1] * i) % MOD;
        findInv(i);
        facinv[i] = (facinv[i-1] * inv[i]) % MOD;
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        cout << comb(x, y) << "\n";
    }

    return 0;
}
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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> trees;
    trees.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
    }

    ll g = trees[1] - trees[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, trees[i] - trees[i-1]);
    }

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (((trees[i] - trees[i-1]) / g) - 1);
    }

    cout << ans << "\n";

    return 0;
}
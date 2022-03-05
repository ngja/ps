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

const int RANGE = 1000000;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> sumOfPrime(RANGE + 1, 1);
    vector<ll> prefixSumOfPrime(RANGE + 1, 0);

    for (int i = 2; i <= RANGE; ++i) {
        for (int j = 1; i * j <= RANGE; ++j) {
            sumOfPrime[i * j] += i;
        }
    }

    for (int i = 1; i <= RANGE; ++i) {
        prefixSumOfPrime[i] = prefixSumOfPrime[i-1] + sumOfPrime[i];
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << prefixSumOfPrime[n] << "\n";
    }

    return 0;
}
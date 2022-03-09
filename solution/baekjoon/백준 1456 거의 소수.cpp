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

const ll RANGE = 10'000'000;
bool isPrime[RANGE + 1];

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    vector<ll> primes;
    fill(isPrime, isPrime + RANGE + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (ll i = 2; i <= RANGE; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= RANGE; j += i) {
                isPrime[j] = false;
            }
        }
    }
    ll a, b;
    cin >> a >> b;

    int ans = 0;
    for (ll p : primes) {

        ll temp = p * p;
        if (temp > b) {
            break;
        }
        while (true) {

            if (temp >= a && temp <= b) {
                ans++;
            }

            if (temp > b / p) {
                break;
            }

            temp *= p;

            if (temp > b) {
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
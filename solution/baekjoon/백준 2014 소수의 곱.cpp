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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<ll> primes;
    primes.resize(k);
    priority_queue<pair<ll, ll>> pq; // <-전체값, 마지막에 곱한값>
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
        pq.push({-primes[i], primes[i]});
    }

    for (int i = 1; i < n; ++i) {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        for (ll p : primes) {
            if (cur.second < p)
                break;

            pq.push({cur.first * p, p});
        }
    }

    pair<ll, ll> ans = pq.top();
    cout << -ans.first << "\n";

    return 0;
}
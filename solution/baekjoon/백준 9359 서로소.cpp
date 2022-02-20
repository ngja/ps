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

vector<bool> isPrime;
vector<ll> primes;

void eratosthenes(int size) {
    isPrime.resize(size, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < size; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < size; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void getPrimes(int size) {
    for (ll i = 0; i < size; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    eratosthenes(100001);
    getPrimes(100001);

    for (int i = 0; i < t; ++i) {
        ll a, b, n;
        cin >> a >> b >> n;

        // n 소인수 분해
        vector<ll> primeFactors;

        for (ll prime : primes) {
            if (n % prime == 0) {

                primeFactors.push_back(prime);
                while (n % prime == 0)
                    n /= prime;
            }
        }

        if (n != 1) {
            primeFactors.push_back(n);
        }

        // 모든 n 의 소인수 조합으로 포함 배제 원리
        int factorsSize = primeFactors.size();

        ll countNotRelativelyPrime = 0;
        for (int j = 1; j < (1 << factorsSize); ++j) { // 모든 소인수 부분집합에 대해서

            int tempFactor = 1;
            int factorCount = 0;

            for (int k = 0; k < factorsSize; ++k) { // k 번째 소인수가 켜지면 포함
                if (!(j & (1<<k)))
                    continue;

                tempFactor *= primeFactors[k];
                factorCount++;
            }

            ll upToB = b / tempFactor;
            ll upToAMinusOne = (a-1) / tempFactor;

            ll sumAtoB = upToB - upToAMinusOne;

            if (factorCount % 2 == 1) {
                countNotRelativelyPrime += sumAtoB;
            } else {
                countNotRelativelyPrime -= sumAtoB;
            }
        }

        ll ans = b - a + 1 - countNotRelativelyPrime;

        cout << "Case #" << i + 1 << ": " << ans << "\n";
    }

    return 0;
}
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

ll oneCount[55];
ll squareNumberOfTwo[55];

ll getOneCount(ll num) {
    ll count = 0;
    bitset<55> bs(num);

    ll leftOneCount = 0;
    for (int i = 54; i >= 0; --i) {
        if (bs[i] == 1) {
            count += ((oneCount[i] + 1) + (leftOneCount * squareNumberOfTwo[i]));
            leftOneCount++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b;
    cin >> a >> b;

    oneCount[1] = 1;
    squareNumberOfTwo[0] = 1;
    squareNumberOfTwo[1] = 2;
    ll additional = 1;
    for (int i = 2; i <= 55; i++) {
        additional *= 2;
        oneCount[i] = 2 * oneCount[i-1] + additional;
        squareNumberOfTwo[i] = 2 * squareNumberOfTwo[i-1];
    }

    ll right = getOneCount(b);
    ll left = getOneCount(a - 1);

    cout << right - left << "\n";

    return 0;
}
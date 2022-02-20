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

    int n;
    cin >> n;

    vector<pair<ll, ll>> info;
    info.resize(n);

    ll minusPopulation = 0L;
    for (int i = 0; i < n; ++i) {
        cin >> info[i].first >> info[i].second;
        minusPopulation -= info[i].second;
    }

    sort(info.begin(), info.end());

    for (int i = 0; i < n; ++i) {
        minusPopulation += 2 * info[i].second;

        if (minusPopulation >= 0) {
            cout << info[i].first << "\n";
            break;
        }
    }


    return 0;
}
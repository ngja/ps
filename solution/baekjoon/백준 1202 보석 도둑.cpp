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
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

bool comp(const pi& a, const pi& b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<ll, ll>> jewels; // {무게, 가격};
    multiset<ll> bags;

    for (int i = 0; i < n; ++i) {
        ll weight, price;
        cin >> weight >> price;
        jewels.push(pi(price, weight));
    }

    for (int i = 0; i < k; ++i) {
        ll bagSize;
        cin >> bagSize;
        bags.insert(bagSize);
    }

    ll ans = 0L;

    while(!bags.empty() && !jewels.empty()) {
        pair<ll, ll> jewel = jewels.top(); jewels.pop();

        const multiset<ll>::iterator &iterator = bags.lower_bound(jewel.second);

        if (iterator == bags.end())
            continue;

        bags.erase(iterator);
        ans += jewel.first;
    }

    cout << ans << "\n";

    return 0;
}

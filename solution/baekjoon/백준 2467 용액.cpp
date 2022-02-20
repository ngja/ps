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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

using namespace std;

bool absSort(const int& a, const int& b) {
    return abs(a) < abs(b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> solutions;
    for (int i = 0; i < n; ++i) {
        ll input;
        cin >> input;
        solutions.push_back(input);
    }

    sort(solutions.begin(), solutions.end(), absSort);

    ll criteria = LL_INF;
    ll ans1, ans2;
    for (int i = 1; i < solutions.size(); i++) {
        ll temp = abs(solutions[i] + solutions[i-1]);
        if (criteria > temp) {
            criteria = temp;
            ans1 = solutions[i];
            ans2 = solutions[i-1];
        }
    }

    if (ans1 > ans2) {
        cout << ans2 << " " << ans1;
    } else {
        cout << ans1 << " " << ans2;
    }
    return 0;
}

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

using namespace std;


pair<ll, ll> point[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> point[i].first >> point[i].second;
    }


    ll area = 0;
    int next = n - 1;
    for (int i = 0; i < n; ++i) {
        area += (point[next].first + point[i].first) * (point[next].second - point[i].second);
        next = i;
    }

    area = abs(area);

    string ans = to_string(area / 2);
    if (area % 2 == 0) {
        ans += ".0";
    } else {
        ans += ".5";
    }

    cout << ans << "\n";

    return 0;
}

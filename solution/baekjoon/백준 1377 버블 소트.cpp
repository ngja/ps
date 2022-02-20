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

int n;
vector<pair<int, int>> numbers; // <value, position>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i].first;
        numbers[i].second = i;
    }

    sort(numbers.begin(), numbers.end());

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int temp = numbers[i].second - i + 1; // 이전 위치 - sorting 후 위치
        if (temp > 0) {
            ans = max(ans, temp);
        }
    }

    cout << ans << "\n";

    return 0;
}
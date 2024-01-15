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

int n, x;
int num[100001];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> x;

    sort(num, num + n);
    int left = 0;
    int right = n - 1;

    int ans = 0;
    while (left < right) {
        int temp = num[left] + num[right];

        if (temp > x) {
            right--;
        } else if (temp < x) {
            left++;
        } else if (temp == x) {
            ans++;
            left++;
            right--;
        }
    }
    cout << ans << "\n";
}
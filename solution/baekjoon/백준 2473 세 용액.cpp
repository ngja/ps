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

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> solutions;
    solutions.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());

    ll criteria = LL_INF;
    ll ans[3];
    bool finish = false;
    for (int i = 0; i < n; ++i) {
        int left = 0;
        int right = n-1;

        while (left < right) {
            if (left == i)
                left++;
            if (right == i)
                right--;

            if (left >= right)
                break;

            ll temp = solutions[i] + solutions[left] + solutions[right];
            if (abs(criteria) > abs(temp)) {
                criteria = temp;
                ans[0] = solutions[i];
                ans[1] = solutions[left];
                ans[2] = solutions[right];
            }

            if (temp > 0)
                right--;
            else if (temp < 0)
                left++;
            else {
                finish = true;
                break;
            }
        }

        if (finish)
            break;
    }

    sort(ans, ans + 3);

    for (int i = 0; i < 3; i++)
        cout << ans[i] << " ";

    return 0;
}
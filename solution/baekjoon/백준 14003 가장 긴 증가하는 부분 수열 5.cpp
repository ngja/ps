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

int n;

vector<int> lis(vector<int> const& a) {
    int s = a.size();
    vector<int> d;
    vector<int> p(s);

    d.push_back(a[0]);
    p[0] = 1;

    for (int i = 1; i < s; ++i) {
        int target = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (target == d.size()) {
            d.push_back(a[i]);
        } else {
            if (d[target] > a[i])
                d[target] = a[i];
        }
        p[i] = target + 1;
    }

    int subsequenceSize = d.size();
    vector<int> subsequence;
    for (int i = p.size() - 1; i >= 0; --i) {
        if (p[i] == subsequenceSize) {
            subsequence.push_back(i);
            subsequenceSize--;
        }
        if (subsequenceSize == 0) {
            break;
        }
    }
    reverse(subsequence.begin(), subsequence.end());

    return subsequence;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> subsequence = lis(numbers);

    cout << subsequence.size() << "\n";
    for (auto k : subsequence) {
        cout << numbers[k] << " ";
    }
    cout << "\n";

    return 0;
}
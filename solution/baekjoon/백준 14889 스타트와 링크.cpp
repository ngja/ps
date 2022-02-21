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

int n;
int num[22][22];
int total = 0;
int ans = INF;

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num[i][j];
            total += num[i][j];
        }
    }

    vector<int> selectList;
    selectList.reserve(n);
    for (int i = 0; i < (n / 2); ++i)
        selectList.push_back(0);
    for (int i = 0; i < (n / 2); ++i)
        selectList.push_back(1);

    do {

        vector<int> temp = {0, 0};
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (selectList[i] != selectList[j])
                    continue;
                temp[selectList[i]] += num[i][j];
                temp[selectList[i]] += num[j][i];
            }
        }

        int tempAns = abs(temp[0] - temp[1]);

        if (ans > tempAns) {
            ans = tempAns;
        }

    } while (next_permutation(selectList.begin(), selectList.end()));

    cout << ans << "\n";

    return 0;
}
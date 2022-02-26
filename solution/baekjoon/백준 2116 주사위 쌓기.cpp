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
vector<vector<int>> diceList;

int opposite(int x) {
    if (x == 0)
        return 5;
    else if (x == 1)
        return 3;
    else if (x == 2)
        return 4;
    else if (x == 3)
        return 1;
    else if (x == 4)
        return 2;
    else // if (x == 5)
        return 0;
}

int getMaxDice(int b, int t) {
    if (t == 6) {
        if (b == 5)
            return 4;
        return 5;
    } else if (b == 6) {
        if (t == 5)
            return 4;
        return 5;
    }
    return 6;
}

int main() {

    cin >> n;
    diceList.assign(n, vector<int>(6));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> diceList[i][j];
        }
    }

    // 0-5 / 1-3 / 2-4
    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        int bottomPos = i;
        int temp = 0;

        temp += getMaxDice(diceList[0][bottomPos], diceList[0][opposite(bottomPos)]);

        for (int j = 1; j < n; ++j) {
            int bottomValue = diceList[j-1][opposite(bottomPos)];

            for (int k = 0; k < 6; ++k) {
                if (bottomValue == diceList[j][k]) {
                    bottomPos = k;
                    break;
                }
            }

            int topValue = diceList[j][opposite(bottomPos)];

            temp += getMaxDice(bottomValue, topValue);
        }

        if (ans < temp)
            ans = temp;
    }

    cout << ans << "\n";

    return 0;
}
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

const int MAX_NUM = 1000000;
bool card[MAX_NUM + 1];
int score[MAX_NUM + 1];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> num(n);
    int maxNum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> num[i];
        card[num[i]] = true;
        if (maxNum < num[i]) {
            maxNum = num[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int now = num[i];
        for (int j = 2 * now; j <= maxNum; j += now) {
            if (card[j]) {
                score[now]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << score[num[i]] << " ";
    }
}
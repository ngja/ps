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

int histogram[100010];
int leftWall[100010];
int rightWall[100010];

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int n;
    cin >> n;


    for (int i = 1; i <= n; ++i) {
        cin >> histogram[i];
    }

    // {높이, 위치} 의 monotone stack
    // 스택은 높이가 높은 순에서 낮은게 더 깊숙히 있는 모노톤 스택.
    stack<pair<int, int>> leftMonotone;
    leftMonotone.push({0, 0});
    for (int i = 1; i <= n; ++i) {
        while (true) {
            pair<int, int> top = leftMonotone.top();
            if (top.first < histogram[i]) {
                leftMonotone.push({histogram[i], i});
                leftWall[i] = top.second;
                break;
            } else {
                leftMonotone.pop();
                if (leftMonotone.empty()) {
                    leftMonotone.push({histogram[i], i});
                    leftWall[i] = 0;
                    break;
                }
            }
        }
    }

    stack<pair<int, int>> rightMonotone;
    rightMonotone.push({0, n+1});
    for (int i = n; i >= 1; --i) {
        while (true) {
            pair<int, int> top = rightMonotone.top();
            if (top.first < histogram[i]) {
                rightMonotone.push({histogram[i], i});
                rightWall[i] = top.second;
                break;
            } else {
                rightMonotone.pop();
                if (rightMonotone.empty()) {
                    rightMonotone.push({histogram[i], i});
                    rightWall[i] = 0;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (rightWall[i] - leftWall[i] - 1) * histogram[i]);
    }

    cout << ans << "\n";

    return 0;
}
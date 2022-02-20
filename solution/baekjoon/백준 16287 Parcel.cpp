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

int w, n;
bool possibleSum[800000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> n;
    vector<int> parcels(n);

    for (int i = 0; i < n; ++i) {
        cin >> parcels[i];
    }

    sort(parcels.begin(), parcels.end());

    bool possible = false;

    // a < b < c < d 라고 가정
    // a + b + c + d = w 를 만족하는 경우 찾기
    for (int i = 1; i < n; ++i) { // 0부터 해도 되는데 0이면 첫 for 문의 의미가 없다.
        // c, d 조합 찾기
        for (int j = i + 1; j < n; ++j) {
            int cdSum = parcels[i] + parcels[j];

            if (cdSum >= w)
                break;

            if (possibleSum[w - cdSum]) {
                possible = true;
                break;
            }
        }

        if (possible)
            break;

        // a, b 조합으로 가능한 거 표시 -> a=j, b=i 이렇게 세팅한 값을 다음 for 문에 사용. 다음 for 문의 i, j는 항상 a, b 보다 크다
        for (int j = 0; j < i; j++) {
            int abSum = parcels[j] + parcels[i];

            if (abSum >= w)
                break;

            possibleSum[abSum] = true;
        }
    }

    if (possible)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
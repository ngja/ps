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
typedef pair<int, int> pi;

int n, m;
int num[1025][1025];
int sum[1025][1025]; // sum[i][j] = sum[i-1][j-1] + ¢²(num[k][j]) + ¥Ò(num[i][k])
int ysum[1025][1025]; //
int xsum[1025][1025];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = num[i][j];
            sum[i][j] += sum[i-1][j-1];
            sum[i][j] += xsum[i][j-1];
            xsum[i][j] = xsum[i][j-1] + num[i][j];
            sum[i][j] += ysum[i-1][j];
            ysum[i][j] = ysum[i-1][j] + num[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        cout << ans << "\n";
    }

    return 0;
}

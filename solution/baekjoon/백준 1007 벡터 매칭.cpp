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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t;

    cin >> t;

    while(t--) {
        int n;

        cin >> n;

        vector<pair<double, double>> coordinates(n); // (y, x)

        for (int i = 0; i < n; ++i) {
            cin >> coordinates[i].first >> coordinates[i].second;
        }

        double ans = INF;


        // n개의 점중 n/2는 +, n/2는 -
        for (int b = 0; b < (1<<n); b++) {
            if (__builtin_popcount(b) == n/2) {

                double y = 0;
                double x = 0;

                for (int i = 0; i < n; i++) {
                    if (b&(1<<i)) {
                        y += coordinates[i].first;
                        x += coordinates[i].second;
                    } else {
                        y -= coordinates[i].first;
                        x -= coordinates[i].second;
                    }
                }

                double tempAns = sqrt((y*y) + (x*x));

                if (ans > tempAns) {
                    ans = tempAns;
                }
            }
        }

        cout << fixed;
        cout.precision(12);
        cout << ans << "\n";
    }

    return 0;
}

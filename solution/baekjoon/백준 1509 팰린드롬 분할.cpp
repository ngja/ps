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

using namespace std;

string pan;
bool palindrome[2505][2505];
int dp[2505];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> pan;

    for (int i = 0; i < pan.length(); i++) {
        palindrome[i][i] = true;
        dp[i] = INF;
        if (i < pan.length() - 1) {
            palindrome[i][i + 1] = (pan[i] == pan[i + 1]);
        }
    }

    for (int i = 2; i < pan.length(); i++) {
        for (int j = 0; j < pan.length() - i; j++) {
            palindrome[j][j + i] = (pan[j] == pan[j + i]) && palindrome[j + 1][j + i - 1];
        }
    }

    dp[0] = 1;

    for (int i = 1; i < pan.length(); i++) {
        if (palindrome[0][i]) {
            dp[i] = 1;
            continue;
        }

        for (int j = 1; j <= i; j++) {
            if (palindrome[i-j+1][i])
                dp[i] = min(dp[i], dp[i-j] + palindrome[i-j+1][i]);
        }
    }

    cout << dp[pan.length()-1] << "\n";


    return 0;
}

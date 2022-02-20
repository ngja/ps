#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int ioi[1000001];

int main() {

    int n, m;
    int sol = 0;
    string s;

    cin >> n;
    cin >> m;
    cin >> s;

    for (int i = 2; i < m; i++) {
        if (s[i] == 'I') {
            if (s[i-1] == 'O' && s[i-2] == 'I') {
                ioi[i] = ioi[i-2] + 1;
                if (ioi[i] >= n) {
                    sol++;
                }
            }
        }
    }

    cout << sol << "\n";

    return 0;
}

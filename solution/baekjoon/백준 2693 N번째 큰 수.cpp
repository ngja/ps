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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int main() {

    int t;
    cin >> t;
    while(t--) {
        vector<int> num(10);

        for (int i = 0; i < 10; ++i) {
            cin >> num[i];
        }
        sort(num.begin(), num.end());

        cout << num[7] << "\n";
    }

    return 0;
}

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

    int n;
    cin >> n;

    while(n--) {
        int t;
        cin >> t;

        int maxPrice = 0;
        string maxPlayer;

        for (int i = 0; i < t; ++i) {

            int curPrice;
            string curPlayer;

            cin >> curPrice >> curPlayer;

            if (maxPrice < curPrice) {
                maxPrice = curPrice;
                maxPlayer = curPlayer;
            }
        }

        cout << maxPlayer << "\n";
    }

    return 0;
}

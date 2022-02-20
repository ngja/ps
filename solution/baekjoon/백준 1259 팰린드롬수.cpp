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

int main() {

    while (true) {
        string num;
        cin >> num;

        if (num == "0")
            break;

        string rev = num;
        reverse_copy(num.begin(), num.end(), rev.begin());

        if (num == rev)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}

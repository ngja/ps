#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;


int getCompressedCoordinate(const vector<int>& v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {

    int n;
    cin >> n;
    vector<int> num(n);
    vector<int> original(n);

    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        original[i] = num[i];
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 0; i < n; ++i) {
        cout << getCompressedCoordinate(num, original[i]) << " ";
    }
    cout << "\n";

    return 0;
}

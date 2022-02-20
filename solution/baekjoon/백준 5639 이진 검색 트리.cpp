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

using namespace std;

typedef long long ll;
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

void postOrder(vector<int>& tree) {
    if (tree.empty()) return;

    int idx = 1;
    while (idx < tree.size()) {
        if (tree[idx] > tree.front()) {
            break;
        }
        idx++;
    }

    vector<int> left = vector<int>(tree.begin() + 1, tree.begin() + idx);
    vector<int> right = vector<int>(tree.begin() + idx, tree.end());

    postOrder(left); // root left
    postOrder(right); // root right
    // root
    cout << tree.front() << "\n";
}

int main() {

    int a;
    vector<int> preOrder;
    while(cin >> a) {
        preOrder.push_back(a);
    }

    postOrder(preOrder);

    return 0;
}

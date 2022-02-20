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

int n;
int inOrder[100010];
int postOrder[100010];

void preOrder(int inBegin, int inLast, int postBegin, int postLast) {
//    cout << "(" << inBegin << ", " << inLast << ", " << postBegin << ", " << postLast << ")\n";
    if (inBegin > inLast)
        return;
    if (postBegin > postLast)
        return;

    cout << postOrder[postLast] << " ";

    int rootPos = inBegin;
    while (rootPos < n) {
        if (inOrder[rootPos] == postOrder[postLast]) {
            break;
        }
        rootPos++;
    }

    preOrder(inBegin, rootPos - 1, postBegin, postBegin + (rootPos - 1 - inBegin));
    preOrder(rootPos + 1, inLast, postBegin + (rootPos - inBegin), postLast - 1);
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        inOrder[i] = num;
    }

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        postOrder[i] = num;
    }

    preOrder(0, n-1, 0, n-1);
    return 0;
}

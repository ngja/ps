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

vector<ll> make_subset_sum(vector<ll>& array) {
    vector<ll> result;
    
    for (int i = 0; i < (1<<array.size()); i++) {
        ll sum = 0;
        for (int j = 0; j < array.size(); j++) {
            if (i&(1<<j)) {
                sum += array[j];
            }
        }
        result.push_back(sum);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<ll> left;
    vector<ll> right;

    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        if (i < n/2) {
            left.push_back(num);
        }  else {
            right.push_back(num);
        }
    }

    vector<ll> leftSums = make_subset_sum(left);
    vector<ll> rightSums = make_subset_sum(right);

    sort(leftSums.begin(), leftSums.end());
    sort(rightSums.begin(), rightSums.end());

    int leftIdx = 0;
    int rightIdx = rightSums.size() - 1;

    ll ans = 0;

    while(true) {
        ll tempSum = leftSums[leftIdx] + rightSums[rightIdx];

        if (tempSum == s) {
            ll leftCount = 0;
            ll leftTemp = leftSums[leftIdx];
            while(leftIdx < leftSums.size() && leftTemp == leftSums[leftIdx]) {
                leftIdx++;
                leftCount++;
            }

            ll rightCount = 0;
            ll rightTemp = rightSums[rightIdx];
            while(rightIdx >= 0 && rightTemp == rightSums[rightIdx]) {
                rightIdx--;
                rightCount++;
            }

            ans += leftCount * rightCount;
        } else if (tempSum > s) {
            rightIdx--;
        } else if (tempSum < s) {
            leftIdx++;
        }

        if (rightIdx < 0 || leftIdx >= leftSums.size()) {
            break;
        }
    }

    if (s == 0)
        ans--;

    cout << ans << "\n";

    return 0;
}

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
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1'000'000'007LL;
const int INF = 2'000'000'000;
const ll LL_INF = 10'000'000'000LL;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int j = 0;
        vector<int> combinedNums;
        for (int i = 0; i < nums1.size(); ++i) {

            while (j < nums2.size() && nums2[j] <= nums1[i]) {
                combinedNums.push_back(nums2[j]);
                j++;
            }

            combinedNums.push_back(nums1[i]);
        }

        while (j < nums2.size()) {
            combinedNums.push_back(nums2[j]);
            j++;
        }

        if (combinedNums.size() % 2 == 0) {
            return (double (combinedNums[combinedNums.size()/2-1]) + double (combinedNums[combinedNums.size()/2])) / 2.0;
        } else {
            return double (combinedNums[combinedNums.size()/2]);
        }
    }
};

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    Solution s = Solution();
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    double ans = s.findMedianSortedArrays(a, b);
    cout << ans << "\n";

    return 0;
}
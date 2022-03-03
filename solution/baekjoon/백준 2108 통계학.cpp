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

int countNumber[8005];

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    numbers.resize(n);

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        sum += numbers[i];
        countNumber[numbers[i]+4000]++;
    }
    std::sort(numbers.begin(), numbers.end());

    int mode = 0;
    int modeCount = 0;
    bool first = true;
    for (int i = 0; i <= 8000; i++) {
        if (modeCount < countNumber[i]) {
            mode = i - 4000;
            modeCount = countNumber[i];
            first = true;
        } else if (modeCount == countNumber[i]) {
            if (first) {
                first = false;
                mode = i - 4000;
            }
        }
    }

    double arithmeticMean = round(sum / n);
    int medianValue = numbers[n/2];

    cout << (int) arithmeticMean << "\n";
    cout << medianValue << "\n";
    cout << mode << "\n";
    cout << numbers[n-1] - numbers[0] << "\n";
    return 0;
}
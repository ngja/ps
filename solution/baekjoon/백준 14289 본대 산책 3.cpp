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
const ll LL_INF = 10000000000LL;
const int INF = 2000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

vector<vector<ll>> matrix;

vector<vector<ll>> identity(int size) {
    vector<vector<ll>> ret;
    ret.assign(size, vector<ll>(size, 0));
    for (int i = 0; i < size; i++)
        ret[i][i] = 1;
    return ret;
}

vector<vector<ll>> multiple(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> ret;
    ret.assign(a.size(), vector<ll>(a.size(), 1));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            ll temp = 0;
            for (int k = 0; k < a.size(); k++) {
                temp += a[i][k] * b[k][j];
                temp %= 1000000007L;
            }
            ret[i][j] = temp;
        }
    }

    return ret;
}

vector<vector<ll>> solution(const vector<vector<ll>>& mat, ll m) {

    if (m == 0)
        return identity(mat.size());

    if (m % 2 == 1)
        return multiple(solution(mat, m - 1), mat);

    vector<vector<ll>> ret = solution(mat, m / 2);

    return multiple(ret, ret);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    matrix.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        matrix[a-1][b-1] = 1;
        matrix[b-1][a-1] = 1;
    }


    ll d;
    cin >> d;

    const vector<vector<ll>> &ansMatrix = solution(matrix, d);

    cout << ansMatrix[0][0] << "\n";

    return 0;
}
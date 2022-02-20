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

long long r = 31;
long long M = 1234567891;

int main() {

    int L;
    string str;

    cin >> L;
    cin >> str;

    long long hash = 0;
    for (int i = 0; i < L; ++i) {
        long long temp = (str[i]-'a'+1);
        for (int j = 0; j < i; j++) {
            temp *= r;
            temp %= M;
        }
        hash += temp;
        hash %= M;
    }

    cout << hash << "\n";

    return 0;
}

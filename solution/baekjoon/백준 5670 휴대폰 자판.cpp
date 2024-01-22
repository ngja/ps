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

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    bool isRoot;

    explicit TrieNode(bool isRoot) : isEnd(false), isRoot(isRoot) {}
};

struct Trie {
    TrieNode* root;

    Trie() : root(new TrieNode(true)) {}

    void insert(const string& word) const {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode(false);
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    int countClick(const string& word) const {
        TrieNode* current = root;
        int count = 0;
        for (char c : word) {
            if (current->children.size() > 1 || current->isRoot || current->isEnd) {
                count++;
            }
            current = current->children[c];
        }
        return count;
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(2);
    int n;
    while (cin >> n) {
        Trie trie;
        vector<string> str;
        str.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            trie.insert(str[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp = trie.countClick(str[i]);
            sum += temp;
        }
        double ans = (double) sum / (double) n;
        ans *= 100;
        ans = round(ans);
        ans /= 100;
        cout << ans << "\n";
    }
}
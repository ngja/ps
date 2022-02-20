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

const int INF = ~(1 << 31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;
int truthCount;
bool personWhoKnowTruth[55]; // true -> 진실을 아는 사람 or 진실을 들어야하는 사람
vector<set<int>> personWhoMeet;
bool checkedPerson[55];
vector<vector<int>> candidateParty;

int main() {

    cin >> n >> m;

    personWhoMeet.resize(n+1);

    cin >> truthCount;

    queue<int> q;

    for (int i = 0; i < truthCount; ++i) {
        int t;
        cin >> t;
        q.push(t);
        checkedPerson[t] = true;
        personWhoKnowTruth[t] = true;
    }

    for (int i = 0; i < m; ++i) {
        int participantCount;
        cin >> participantCount;
        vector<int> partyParticipants;
        bool canLie = true;
        for (int j = 0; j < participantCount; ++j) {
            int id;
            cin >> id;
            if (personWhoKnowTruth[id]) {
                canLie = false;
            }
            partyParticipants.push_back(id);
        }

        if (canLie) {
            candidateParty.push_back(partyParticipants);
        }

        for (int id : partyParticipants) {
            for (int meetId : partyParticipants) {
                if (id != meetId) {
                    personWhoMeet[id].insert(meetId);
                }
            }
        }
    }

    while(!q.empty()) {
        int target = q.front(); q.pop();

        for (int id : personWhoMeet[target]) {
            if (!checkedPerson[id]) {
                q.push(id);
                checkedPerson[id] = true;
                personWhoKnowTruth[id] = true;
            }
        }
    }

    int ans = 0;

    for (vector<int> party : candidateParty) {
        bool canLie = true;
        for (int id : party) {
            if (personWhoKnowTruth[id]) {
                canLie = false;
                break;
            }
        }

        if (canLie) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}

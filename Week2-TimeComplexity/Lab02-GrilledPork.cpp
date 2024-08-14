#include <iostream>
#include <vector>
using namespace std;

int findMaxUnreachable(int p1, int p2, int p3, int p4, int n) {
    vector<bool> reachable(n + 1, false);
    reachable[0] = true;

    for (int i = 0; i <= n; ++i) {
        if (reachable[i]) {
            if (i + p1 <= n) reachable[i + p1] = true;
            if (i + p2 <= n) reachable[i + p2] = true;
            if (i + p3 <= n) reachable[i + p3] = true;
            if (i + p4 <= n) reachable[i + p4] = true;
        }
    }

    int max_unreachable = 0;
    for (int i = 0; i <= n; ++i) {
        if (!reachable[i]) {
            max_unreachable = i;
        }
    }

    return max_unreachable;
}

int main() {
    int p1, p2, p3, p4, n;
    cin >> p1 >> p2 >> p3 >> p4 >> n;

    cout << findMaxUnreachable(p1, p2, p3, p4, n) << endl;
    return 0;
}
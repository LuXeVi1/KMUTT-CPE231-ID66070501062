#include <iostream>
#include <vector>
using namespace std;

int findMaxUnreachable(int p1, int p2, int p3, int p4, int n, int &operation_count) {
    vector<bool> reachable(n + 1, false);
    reachable[0] = true;
    operation_count++;

    for (int i = 0; i <= n; ++i) {
        operation_count++;
        if (reachable[i]) {
            operation_count++;
            if (i + p1 <= n) {
                reachable[i + p1] = true;
                operation_count++;
            }
            if (i + p2 <= n) {
                reachable[i + p2] = true;
                operation_count++;
            }
            if (i + p3 <= n) {
                reachable[i + p3] = true;
                operation_count++;
            }
            if (i + p4 <= n) {
                reachable[i + p4] = true;
                operation_count++;
            }
        }
    }

    int max_unreachable = 0;
    for (int i = 0; i <= n; ++i) {
        operation_count++;
        if (!reachable[i]) {
            max_unreachable = i;
            operation_count++;
        }
    }

    return max_unreachable;
}

int main() {
    int p1, p2, p3, p4, n;
    cin >> p1 >> p2 >> p3 >> p4 >> n;

    int operation_count = 0;
    int result = findMaxUnreachable(p1, p2, p3, p4, n, operation_count);
    
    return 0;
}
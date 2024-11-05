#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int maxSticks;
    int n;
    vector<int> packages;
    vector<bool> possible;

    int findLargestImpossible() {
        possible.assign(maxSticks + 1, false);
        possible[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxSticks - packages[i]; j++) {
                if (possible[j]) {
                    possible[j + packages[i]] = true;
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= maxSticks; i++) {
            if (!possible[i]) {
                result = i;
            }
        }

        return result;
    }

public:
    void solve() {
        cin >> maxSticks;
        cin >> n;
        
        packages.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> packages[i];
        }

        cout << findLargestImpossible() << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    solution.solve();
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> sequence;
    vector<vector<int> > dp;
    int n;
    
    int solve(int i, bool isAscending) {
        if (i == 0) return 1;
        
        if (dp[i][isAscending] != -1) return dp[i][isAscending];
        
        int result = 1; 
        
        for (int j = 0; j < i; j++) {
            if (isAscending) {
                if (sequence[j] < sequence[i]) {
                    result = max(result, solve(j, false) + 1);
                }
            } else {
                if (sequence[j] > sequence[i]) {
                    result = max(result, solve(j, true) + 1);
                }
            }
        }
        
        return dp[i][isAscending] = result;
    }

public:
    void findLongestZigzag() {
        cin >> n;
        sequence.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
        
        dp.assign(n, vector<int>(2, -1));
        
        vector<int> ascendingResults(n);
        vector<int> descendingResults(n);
        
        for (int i = 0; i < n; i++) {
            ascendingResults[i] = solve(i, true);
            descendingResults[i] = solve(i, false);
        }
        
        for (int i = 0; i < n; i++) {
            cout << ascendingResults[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < n; i++) {
            cout << descendingResults[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    solution.findLongestZigzag();
    
    return 0;
}
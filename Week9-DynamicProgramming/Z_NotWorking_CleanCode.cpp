#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> sequence;
    vector<vector<int>> dp;
    int n;
    
    int solve(int index, bool isAscending) {
        if (index == 0) return 1;
        
        if (dp[index][isAscending] != -1) return dp[index][isAscending];
        
        int maxLength = 1; 
        
        for (int j = 0; j < index; j++) {
            if (isAscending) {
                if (sequence[j] < sequence[index]) {
                    maxLength = max(maxLength, solve(j, false) + 1);
                }
            } else {
                if (sequence[j] > sequence[index]) {
                    maxLength = max(maxLength, solve(j, true) + 1);
                }
            }
        }
        
        return dp[index][isAscending] = maxLength;
    }

    void readInput() {
        cin >> n;
        sequence.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
    }

    void initializeDP() {
        dp.assign(n, vector<int>(2, -1));
    }

    void printResults(const vector<int>& results) {
        for (int result : results) {
            cout << result << " ";
        }
        cout << endl;
    }

public:
    void findLongestZigzag() {
        readInput();
        initializeDP();
        
        vector<int> ascendingResults(n);
        vector<int> descendingResults(n);
        
        for (int i = 0; i < n; i++) {
            ascendingResults[i] = solve(i, true);
            descendingResults[i] = solve(i, false);
        }
        
        printResults(ascendingResults);
        printResults(descendingResults);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    solution.findLongestZigzag();
    
    return 0;
}
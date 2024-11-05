#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<long long> > dp;
    vector<pair<int, int> > items;
    int n, maxMessiness;

    long long solve(int idx, int messiness) {
        if (messiness < 0) return -1e18;
        if (idx == n) return 0;
        
        if (dp[idx][messiness] != -1) return dp[idx][messiness];
        
        long long result = solve(idx + 1, messiness);
        
        if (messiness >= items[idx].first) {
            result = max(result, 
                        items[idx].second + solve(idx + 1, messiness - items[idx].first));
        }
        
        return dp[idx][messiness] = result;
    }

public:
    long long findMaxLuxury() {
        cin >> n;
        items.resize(n);
        
        for (int i = 0; i < n; i++) {
            int messiness, luxury;
            cin >> messiness >> luxury;
            items[i] = make_pair(messiness, luxury); 
        }
        
        cin >> maxMessiness;
        
        dp.assign(n + 1, vector<long long>(maxMessiness + 1, -1));
        
        return solve(0, maxMessiness);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    cout << solution.findMaxLuxury() << endl;
    
    return 0;
}
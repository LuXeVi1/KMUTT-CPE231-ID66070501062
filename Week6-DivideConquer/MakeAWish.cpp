#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxMongkolSum(const vector<int>& mongkol) {
    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < mongkol.size(); i++) {
        currentSum = currentSum + mongkol[i];
        
        if (maxSum < currentSum)
            maxSum = currentSum;

        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> mongkol(n);
    for (int i = 0; i < n; i++) {
        cin >> mongkol[i];
    }

    int result = maxMongkolSum(mongkol);

    cout << result << endl;

    return 0;
}

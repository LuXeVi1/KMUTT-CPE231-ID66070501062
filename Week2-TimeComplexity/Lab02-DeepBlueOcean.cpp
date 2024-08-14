#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// int add_sub_operations = 0;
// int mul_div_operations = 0;
// int comparison_operations = 0;

int countWays(int n, int v, const unordered_set<int>& restricted, vector<bool>& used) {
    if (n == 0) {
        return 1;
    }

    int total_ways = 0;
    for (int i = 1; i <= used.size(); ++i) {
        // comparison_operations++;
        if (!used[i - 1] && (n != v || restricted.find(i) == restricted.end())) {
            // comparison_operations++;
            used[i - 1] = true;
            total_ways += countWays(n - 1, v, restricted, used);
            // add_sub_operations++;
            used[i - 1] = false;
        }
    }

    return total_ways;
}

int calculateWays(int n, int v, const vector<int>& student_ids, const vector<int>& restricted_ids) {
    unordered_set<int> restricted_positions;

    for (int restricted_id : restricted_ids) {
        int position = -1;
        for (int i = 0; i < student_ids.size(); ++i) {
            // comparison_operations++;
            if (student_ids[i] == restricted_id) {
                // comparison_operations++;
                position = i + 1;
                // add_sub_operations++;
                break;
            }
        }
        restricted_positions.insert(position);
    }

    vector<bool> used(n, false);
    return countWays(n, v, restricted_positions, used);
}

int main() {
    int n, v, p;
    cin >> n >> v;

    vector<int> student_ids(n);
    for (int i = 0; i < n; ++i) {
        cin >> student_ids[i];
    }

    cin >> p;
    vector<int> restricted_ids(p);
    for (int i = 0; i < p; ++i) {
        cin >> restricted_ids[i];
    }

    int result = calculateWays(n, v, student_ids, restricted_ids);
    cout << result << endl;

    return 0;
}
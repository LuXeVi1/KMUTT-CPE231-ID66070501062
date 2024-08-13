#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Counters for basic operations
int add_sub_operations = 0;
int mul_div_operations = 0;
int comparison_operations = 0;

// Recursive function to count valid arrangements
int countWays(int n, int v, const unordered_set<int>& restricted, vector<bool>& used) {
    if (n == 0) {
        return 1; // Base case: all students are arranged
    }

    int total_ways = 0;
    for (int i = 1; i <= used.size(); ++i) {
        comparison_operations++; // for the loop condition
        if (!used[i - 1] && (n != v || restricted.find(i) == restricted.end())) {
            comparison_operations++; // for the if condition
            used[i - 1] = true;
            total_ways += countWays(n - 1, v, restricted, used);
            add_sub_operations++; // for the addition
            used[i - 1] = false;
        }
    }

    return total_ways;
}

// Function to calculate the number of valid arrangements
int calculateWays(int n, int v, const vector<int>& student_ids, const vector<int>& restricted_ids) {
    unordered_set<int> restricted_positions;

    // Create a mapping from student_ids to their positions
    vector<int> id_to_position(student_ids.size() + 1, -1);
    for (int i = 0; i < student_ids.size(); ++i) {
        id_to_position[student_ids[i]] = i + 1;
    }

    // Convert restricted_ids to positions
    for (int restricted_id : restricted_ids) {
        comparison_operations++; // for the loop condition
        int position = id_to_position[restricted_id];
        if (position != -1) {
            restricted_positions.insert(position);
        }
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

    // Output the count of basic operations
    cout << "Add/Sub operations: " << add_sub_operations << endl;
    cout << "Mul/Div operations: " << mul_div_operations << endl;
    cout << "Comparison operations: " << comparison_operations << endl;

    return 0;
}

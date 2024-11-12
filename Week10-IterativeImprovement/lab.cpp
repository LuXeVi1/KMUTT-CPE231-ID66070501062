#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void matchInternsToCompanies(int n, vector<vector<int>>& companyPreferences, vector<vector<int>>& studentPreferences) {
    vector<int> companyAssigned(n, -1); // Current student each company has accepted
    vector<int> studentCompany(n, -1);  // Current company each student is assigned to
    vector<int> studentRank(n, 0);      // Track student's current preference rank for the next application
    vector<vector<int>> companyRank(n, vector<int>(n)); // Rank of each student for every company
    
    // Precompute company ranks for faster lookup
    for (int company = 0; company < n; ++company) {
        for (int rank = 0; rank < n; ++rank) {
            companyRank[company][companyPreferences[company][rank]] = rank;
        }
    }

    queue<int> freeStudents;
    for (int i = 0; i < n; ++i) {
        freeStudents.push(i);
    }

    while (!freeStudents.empty()) {
        int student = freeStudents.front();
        freeStudents.pop();

        int preferredCompany = studentPreferences[student][studentRank[student]++];
        int currentAssignedStudent = companyAssigned[preferredCompany];

        if (currentAssignedStudent == -1 || companyRank[preferredCompany][student] < companyRank[preferredCompany][currentAssignedStudent]) {
            if (currentAssignedStudent != -1) {
                studentCompany[currentAssignedStudent] = -1; // Make the previous student free
                freeStudents.push(currentAssignedStudent);
            }
            companyAssigned[preferredCompany] = student;
            studentCompany[student] = preferredCompany;
        } else {
            freeStudents.push(student); // Keep student free to try next preference
        }
    }

    for (int student = 0; student < n; ++student) {
        cout << student << " " << studentCompany[student] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> companyPreferences(n, vector<int>(n));
    vector<vector<int>> studentPreferences(n, vector<int>(n));

    // Input company preferences
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> companyPreferences[i][j];
        }
    }

    // Input student preferences
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> studentPreferences[i][j];
        }
    }

    matchInternsToCompanies(n, companyPreferences, studentPreferences);

    return 0;
}

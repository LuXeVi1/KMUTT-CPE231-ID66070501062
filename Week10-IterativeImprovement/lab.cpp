#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void matchInternsToCompanies(int n, vector<vector<int>>& companyPreferences, vector<vector<int>>& studentPreferences) {
    vector<int> companyAssigned(n, -1);
    vector<int> studentCompany(n, -1);
    vector<int> studentRank(n, 0);

    bool freeStudents = true;
    while (freeStudents) {
        freeStudents = false;

        for (int student = 0; student < n; ++student) {
            if (studentCompany[student] == -1) {
                freeStudents = true;
                int preferredCompany = studentPreferences[student][studentRank[student]];
                int currentAssignedStudent = companyAssigned[preferredCompany];

                bool prefersNewStudent = (currentAssignedStudent == -1) ||
                                         (find(companyPreferences[preferredCompany].begin(),
                                               companyPreferences[preferredCompany].end(),
                                               student) <
                                          find(companyPreferences[preferredCompany].begin(),
                                               companyPreferences[preferredCompany].end(),
                                               currentAssignedStudent));

                if (prefersNewStudent) {
                    companyAssigned[preferredCompany] = student;
                    studentCompany[student] = preferredCompany;

                    if (currentAssignedStudent != -1) {
                        studentCompany[currentAssignedStudent] = -1;
                    }
                }

                ++studentRank[student];
            }
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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> companyPreferences[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> studentPreferences[i][j];
        }
    }

    matchInternsToCompanies(n, companyPreferences, studentPreferences);

    return 0;
}

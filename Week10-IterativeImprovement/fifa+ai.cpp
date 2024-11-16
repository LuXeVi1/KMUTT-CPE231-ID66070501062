#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printingList(const vector<int>& studentPartner) {
    int key = 0;
    for (int value : studentPartner) {
        cout << key++ << " " << value << "\n";
    }
}

vector<vector<int>> preprocessStudentPreferences(const vector<vector<int>>& s, int n) {
    vector<vector<int>> studentRank(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            studentRank[i][s[i][j]] = j;
        }
    }
    return studentRank;
}

void matching(const vector<vector<int>>& c, const vector<vector<int>>& s, vector<int>& studentPartner, int n) {
    vector<int> nextProposal(n, 0);
    vector<int> companyPartner(n, -1);
    queue<int> freeCompanies;
    
    vector<vector<int>> studentRank = preprocessStudentPreferences(s, n);
    
    for (int i = 0; i < n; i++) {
        freeCompanies.push(i);
    }

    while (!freeCompanies.empty()) {
        int comp = freeCompanies.front();
        freeCompanies.pop();

        int student = c[comp][nextProposal[comp]];
        nextProposal[comp]++;

        if (studentPartner[student] == -1) {
            studentPartner[student] = comp;
            companyPartner[comp] = student;
        } else {
            int currentComp = studentPartner[student];
            if (studentRank[student][comp] < studentRank[student][currentComp]) {
                studentPartner[student] = comp;
                companyPartner[comp] = student;
                companyPartner[currentComp] = -1;
                freeCompanies.push(currentComp);
            } else {
                freeCompanies.push(comp);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n, 0)), s(n, vector<int>(n, 0));
    vector<int> studentPartner(n, -1);
    
    // Read company preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    
    // Read student preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    
    matching(c, s, studentPartner, n);
    printingList(studentPartner);

    return 0;
}

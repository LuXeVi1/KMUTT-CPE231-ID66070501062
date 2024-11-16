#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class InternshipMatcher {
private:
    int n;
    vector<vector<int>> companyPrefs;
    vector<vector<int>> studentPrefs;
    vector<int> studentMatch;
    vector<int> companyMatch;
    vector<int> nextProposal;
    vector<vector<int>> companyRanks;
    vector<vector<int>> studentRanks;

    void computeRankings() {
        companyRanks.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                companyRanks[i][companyPrefs[i][j]] = j;
            }
        }

        studentRanks.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                studentRanks[i][studentPrefs[i][j]] = j;
            }
        }
    }

public:
    InternshipMatcher(int size) : n(size), studentMatch(n, -1), companyMatch(n, -1), nextProposal(n, 0) {
        companyPrefs.resize(n, vector<int>(n));
        studentPrefs.resize(n, vector<int>(n));
    }
    
    void setCompanyPreferences(const vector<vector<int>>& prefs) {
        companyPrefs = prefs;
    }
    
    void setStudentPreferences(const vector<vector<int>>& prefs) {
        studentPrefs = prefs;
        computeRankings();
    }
    
    void match() {
        queue<int> freeCompanies;
        for (int i = 0; i < n; i++) {
            freeCompanies.push(i);
        }
        
        while (!freeCompanies.empty()) {
            int company = freeCompanies.front();
            freeCompanies.pop();

            int student = companyPrefs[company][nextProposal[company]++];
            
            if (studentMatch[student] == -1) {
                studentMatch[student] = company;
                companyMatch[company] = student;
            } else {
                int currentCompany = studentMatch[student];
                if (studentRanks[student][company] < studentRanks[student][currentCompany]) {
                    studentMatch[student] = company;
                    companyMatch[company] = student;
                    companyMatch[currentCompany] = -1;
                    freeCompanies.push(currentCompany);
                } else {
                    freeCompanies.push(company);
                }
            }
        }
    }
    
    void printMatches() const {
        for (int i = 0; i < n; i++) {
            cout << i << " " << studentMatch[i] << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    
    InternshipMatcher matcher(n);
    
    vector<vector<int>> companyPrefs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> companyPrefs[i][j];
        }
    }
    matcher.setCompanyPreferences(companyPrefs);
    
    vector<vector<int>> studentPrefs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> studentPrefs[i][j];
        }
    }
    matcher.setStudentPreferences(studentPrefs);
    
    matcher.match();
    matcher.printMatches();
    
    return 0;
}

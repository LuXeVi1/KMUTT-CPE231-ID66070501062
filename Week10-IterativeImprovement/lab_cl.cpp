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
    vector<vector<int>> companyRanks;
    vector<int> nextProposal;

    void computeRankings() {
        companyRanks.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                companyRanks[i][companyPrefs[i][j]] = j;
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
        queue<int> freeStudents;
        for (int i = 0; i < n; i++) {
            freeStudents.push(i);
        }
        
        while (!freeStudents.empty()) {
            int student = freeStudents.front();
            freeStudents.pop();

            int company = studentPrefs[student][nextProposal[student]];
            nextProposal[student]++;

            if (companyMatch[company] == -1) {
                companyMatch[company] = student;
                studentMatch[student] = company;
            }
            else if (companyRanks[company][student] < companyRanks[company][companyMatch[company]]) {
                int otherStudent = companyMatch[company];
                studentMatch[otherStudent] = -1; // Free the previously matched student
                freeStudents.push(otherStudent);  // Re-add the other student to free students
                
                companyMatch[company] = student;
                studentMatch[student] = company;
            }
            else {
                freeStudents.push(student); // Student remains free, try the next preference
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

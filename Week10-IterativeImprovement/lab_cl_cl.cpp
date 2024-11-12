#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class InternshipMatcher {
private:
    int n; // number of students/companies
    vector<vector<int>> companyPrefs; // company preferences
    vector<vector<int>> studentPrefs; // student preferences
    vector<int> studentMatch; // current company for each student
    vector<int> companyMatch; // current student for each company
    vector<unordered_map<int, int>> companyRanks; // ranking map for companies

    void computeRankings() {
        companyRanks.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                companyRanks[i][companyPrefs[i][j]] = j;
            }
        }
    }

    bool prefersCompany(int s, int c1, int c2) {
        if (c2 == -1) return true;
        
        auto it1 = companyRanks[s].find(c1);
        auto it2 = companyRanks[s].find(c2);
        return it1->second < it2->second;
    }

public:
    InternshipMatcher(int size) : n(size) {
        companyPrefs.resize(n, vector<int>(n));
        studentPrefs.resize(n, vector<int>(n));
        studentMatch.resize(n, -1);
        companyMatch.resize(n, -1);
    }

    void setCompanyPreferences(const vector<vector<int>>& prefs) {
        companyPrefs = prefs;
        computeRankings();
    }

    void setStudentPreferences(const vector<vector<int>>& prefs) {
        studentPrefs = prefs;
    }

    void match() {
        vector<int> freeStudents(n);
        for (int i = 0; i < n; i++) {
            freeStudents[i] = i;
        }
        int freeStudentCount = n;

        while (freeStudentCount > 0) {
            int s = freeStudents[--freeStudentCount];
            
            for (int i = 0; i < n && studentMatch[s] == -1; i++) {
                int c = studentPrefs[s][i];
                
                if (companyMatch[c] == -1) {
                    studentMatch[s] = c;
                    companyMatch[c] = s;
                }
                else if (prefersCompany(c, s, companyMatch[c])) {
                    freeStudents[freeStudentCount++] = companyMatch[c];
                    studentMatch[s] = c;
                    studentMatch[companyMatch[c]] = -1;
                    companyMatch[c] = s;
                }
            }
        }
    }

    void printMatches() {
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
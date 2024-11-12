#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class InternshipMatcher {
private:
    int n;
    vector<vector<int> > companyPrefs;
    vector<vector<int> > studentPrefs;
    vector<int> studentMatch;
    vector<int> companyMatch;
    vector<vector<int> > companyRanks;
    
    void computeRankings() {
        companyRanks.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                companyRanks[i][companyPrefs[i][j]] = j;
            }
        }
    }
    
    bool prefersCompany(int s, int c1, int c2) {
        if (c2 == -1) return true;
        
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < n; i++) {
            if (studentPrefs[s][i] == c1) pos1 = i;
            if (studentPrefs[s][i] == c2) pos2 = i;
        }
        return pos1 < pos2;
    }
    
public:
    InternshipMatcher(int size) : n(size) {
        companyPrefs.resize(n, vector<int>(n));
        studentPrefs.resize(n, vector<int>(n));
        studentMatch.resize(n, -1);
        companyMatch.resize(n, -1);
    }
    
    void setCompanyPreferences(const vector<vector<int> >& prefs) {
        companyPrefs = prefs;
        computeRankings();
    }
    
    void setStudentPreferences(const vector<vector<int> >& prefs) {
        studentPrefs = prefs;
    }
    
    void match() {
        queue<int> freeStudents;
        for (int i = 0; i < n; i++) {
            freeStudents.push(i);
        }
        
        while (!freeStudents.empty()) {
            int s = freeStudents.front();
            freeStudents.pop();
            
            for (int i = 0; i < n && studentMatch[s] == -1; i++) {
                int c = studentPrefs[s][i];
                
                if (companyMatch[c] == -1) {
                    studentMatch[s] = c;
                    companyMatch[c] = s;
                }

                else if (companyRanks[c][s] < companyRanks[c][companyMatch[c]]) {
                    freeStudents.push(companyMatch[c]);
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
    
    vector<vector<int> > companyPrefs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> companyPrefs[i][j];
        }
    }
    matcher.setCompanyPreferences(companyPrefs);
    
    vector<vector<int> > studentPrefs(n, vector<int>(n));
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
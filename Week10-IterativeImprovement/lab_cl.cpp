#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class InternshipMatcher {
private:
    int n; // number of students/companies
    vector<vector<int>> companyPrefs; // company preferences
    vector<vector<int>> studentPrefs; // student preferences
    vector<int> studentMatch; // current company for each student
    vector<int> companyMatch; // current student for each company
    vector<vector<int>> companyRanks; // ranking matrix for companies
    
    // Convert preferences to rankings for easier comparison
    void computeRankings() {
        companyRanks.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                companyRanks[i][companyPrefs[i][j]] = j;
            }
        }
    }
    
    // Check if student s prefers company c1 over their current match c2
    bool prefersCompany(int s, int c1, int c2) {
        if (c2 == -1) return true;
        
        // Find positions of c1 and c2 in student s's preference list
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
    
    void setCompanyPreferences(const vector<vector<int>>& prefs) {
        companyPrefs = prefs;
        computeRankings();
    }
    
    void setStudentPreferences(const vector<vector<int>>& prefs) {
        studentPrefs = prefs;
    }
    
    // Implement stable matching algorithm
    void match() {
        // Use a vector instead of a queue for better performance
        vector<int> freeStudents(n);
        for (int i = 0; i < n; i++) {
            freeStudents[i] = i;
        }
        int freeStudentCount = n;
        
        // Continue until all students are matched
        while (freeStudentCount > 0) {
            int s = freeStudents[--freeStudentCount];
            
            // Try each company in order of student's preference
            for (int i = 0; i < n && studentMatch[s] == -1; i++) {
                int c = studentPrefs[s][i];
                
                // If company is free, match them
                if (companyMatch[c] == -1) {
                    studentMatch[s] = c;
                    companyMatch[c] = s;
                }
                // If company prefers this student over current match
                else if (companyRanks[c][s] < companyRanks[c][companyMatch[c]]) {
                    // Add current match back to free students
                    freeStudents[freeStudentCount++] = companyMatch[c];
                    // Update matches
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
    
    // Read company preferences
    vector<vector<int>> companyPrefs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> companyPrefs[i][j];
        }
    }
    matcher.setCompanyPreferences(companyPrefs);
    
    // Read student preferences
    vector<vector<int>> studentPrefs(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> studentPrefs[i][j];
        }
    }
    matcher.setStudentPreferences(studentPrefs);
    
    // Find and print matches
    matcher.match();
    matcher.printMatches();
    
    return 0;
}
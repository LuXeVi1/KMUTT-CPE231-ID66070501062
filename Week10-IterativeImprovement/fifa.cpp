#include<iostream>
#include<vector>
#include <queue>


using namespace std;

void printingList(const vector<int> & studentPartner) {
    int key = 0;
    for (int value : studentPartner) {
        cout << key++ << " " << value << "\n";
    }
}

void matching(const vector<vector<int>>& c, const vector<vector<int>>& s, vector<int>& studentPartner, int n) {
    vector<int> nextProposal(n, 0);
    vector<bool> companyFree(n, true);
    queue<int> freeCompanies;
    int freeCount = n;

    for (int i = 0; i < n; i++) {
        freeCompanies.push(i);
    }

    while (freeCount > 0) {
        int comp = freeCompanies.front();
        freeCompanies.pop();

        int student = c[comp][nextProposal[comp]++];

        if (studentPartner[student] == -1) {
            studentPartner[student] = comp;
            companyFree[comp] = false;
            freeCount--;
        } else {
            int currentComp = studentPartner[student];

            if (s[student][comp] < s[student][currentComp]) {
                studentPartner[student] = comp;
                companyFree[comp] = false;
                companyFree[currentComp] = true;

                freeCompanies.push(currentComp);
            }
        }

        if (companyFree[comp]) {
            freeCompanies.push(comp);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> c(n,vector<int>(n,0)) , s(n,vector<int>(n,0));
    vector<int> studentPartner(n, -1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> s[i][j];
        }
    }
    matching(c,s,studentPartner,n);
    printingList(studentPartner);

    return 0;
}

/*
4
3 1 2 0
1 0 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3

5
1 4 2 3 0
1 0 2 4 3
0 1 2 3 4
4 3 2 0 1
0 2 4 1 3
0 1 2 3 4
0 3 4 2 1
3 4 2 1 0
4 1 0 2 3
3 4 1 0 2

*/
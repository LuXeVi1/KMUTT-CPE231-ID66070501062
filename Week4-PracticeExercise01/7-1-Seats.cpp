#include <iostream>
#include <vector>
using namespace std;

// Structure to hold student ID and score
struct Student {
    int id;
    int score;
};

// Function to swap two students
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Selection sort based on the conditions
void selectionSort(vector<Student> &students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            // Higher score comes first, if scores are equal, the earlier one in the list remains first
            if (students[j].score > students[maxIndex].score || 
                (students[j].score == students[maxIndex].score && j < maxIndex)) {
                maxIndex = j;
            }
        }
        // Swap the found max element with the first element of the unsorted part
        swap(students[i], students[maxIndex]);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].score;
    }
    
    selectionSort(students);
    
    // Output the sorted student IDs
    for (int i = 0; i < n; i++) {
        cout << students[i].id << endl;
    }
    
    return 0;
}

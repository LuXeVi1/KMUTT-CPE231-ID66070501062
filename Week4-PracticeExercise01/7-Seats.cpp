/*
ภาควิชาได้จัดงานกิจกรรมจับฉลากวันขึ้นปีใหม่ 2568 โดยให้นักศึกษาเข้ามาจับจองที่นั่งเก้าอี้เรียงเป็น
เส้นตรงเพื่อเรียงลำดับว่าใครจะได้จับฉลากก่อน โดยนั่งเรียงจากหน้าไปหลังโดยข้างหน้าคือคนที่จะได้จับฉลาก
ก่อน แลกข้างหลังคือคนที่จะได้จับฉลากทีหลัง
หลังจากนักศึกษาเข้ามาจับจองที่นั่งของตัวเองเรียบร้อยแล้ว อาจารย์ที่ปรึกษาของกิจกรรมนี้ (ดร.ทวีชัย
นันทวิสุทธิวงศ์) เพิ่งนึกได้ว่า เราจะให้นักศึกษาที่ได้รวมรายวิชา CPE231 มากที่สุดให้ได้นั่งด้านหน้าสุดก่อน
(หมายความว่าได้จับฉลากก่อน) ส่วนคนที่ได้คะแนนเท่า ๆ กัน ให้ใช้กฏว่ามาก่อนได้ก่อน (First come, first
served)
สมมติให้นักศึกษาที่มานั่งที่นั่งเป็นลำดับดังนี้ (บนลงล่างเปรียบเสมือนหน้าไปหลัง) ตัวเลขในวงเล็บคือ
คะแนนสอบวิชา CPE231
1040 (70)
3479 (40)
3411 (40)
3441 (70)
3442 (81)
3487 (70)
3478 (70)
5217 (81)
3450 (99)
3400 (1)
เมื่อให้เปลี่ยนไปเรียงลำดับตามที่อ.วีให้เงื่อนไขเอาไว้ จะได้ลำดับแุถวใหม่คือ
3450 (99)
3442 (81)
5217 (81)
1040 (70)
3441 (70)
3487 (70)
3478 (70)
3479 (40)
3411 (40)
3400 (1)
งานของคุณ
จงหาว่า หากมีรายชื่อนักศึกษาที่นั่งเก้าอี้ แล้วเปลี่ยนลำดับตามเงื่อนไขด้านบนต่อไปนี้ จะได้ลำดับใหม่ของนักศึกษาเป็นอย่างไรบ้าง โดยมีข้อกำหนดว่านักศึกษาต้องใช้ Selection Sort เท่านั้น
ข้อมูลนำเข้า (Input)
บรรทัด 1 จำนวนเต็ม n แทนจำนวนนักศึกษา
ตั้งแต่บรรทัดที่ 2
ถึง n + 1
จำนวนเต็มบรรทัดละ 2 ตัว แทนด้วย ai และ bi แทนรหัสนักศึกษาและคะแนน
ของนักศึกษาตามลำดับ โดยที่ ai เป็นจำนวนเต็ม 4 หลัก และ 0 ≤ bi ≤
100, 1 ≤ i ≤ n
ข้อมูลส่งออก (Output)
บรรทัด 1 ถึง n จำนวนเต็มแทนรหัสนักศึกษาตามลำดับในเงื่อนไข บรรทัดละ 1 ตัว
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input Output
10
1040 70
3479 40
3411 40
3441 70
3442 81
3487 70
3478 70
5217 81
3450 99
3400 1
3450
3442
5217
1040
3441
3487
3478
3479
3411
3400
12
3427 78
3490 87
3402 90
3401 90
3468 78
3475 90
3410 78
3407 90
3422 83
3438 90
3497 92
3446 70
3497
3402
3401
3475
3407
3438
3490
3422
3427
3468
3410
3446
*/

/*
Plan
Define the Student Structure: Create a structure to hold student information, including id and score.
Implement selectionSort Function: Sort the students based on their scores in descending order. If scores are equal, maintain the original order.
Read Input in main Function: Read the number of students and their details.
Sort the Students: Call the selectionSort function to sort the students.
Output the Sorted Students: Print the id of each student in the sorted order.
<------------------------------------------------------------------------>
Pseudocode
struct Student:
    int id
    int score

function selectionSort(students, n):
    for i from 0 to n-2:
        maxIdx = i
        for j from i+1 to n-1:
            if students[j].score > students[maxIdx].score or 
               (students[j].score == students[maxIdx].score and j < maxIdx):
                maxIdx = j
        if maxIdx != i:
            swap students[i] and students[maxIdx]

main:
    read n
    initialize students as a list of n Student objects
    for i from 0 to n-1:
        read students[i].id and students[i].score

    call selectionSort(students, n)

    for each student in students:
        print student.id
<------------------------------------------------------------------------>
Explanation
Explanation
Define the Student Structure: The Student structure is defined to hold the id and score of each student.
struct Student {
    int id;
    int score;
};
Implement selectionSort Function: The selectionSort function sorts the students based on their scores in descending order. If two students have the same score, the one who appears earlier in the input list is considered first.
void selectionSort(vector<Student>& students, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].score > students[maxIdx].score || 
                (students[j].score == students[maxIdx].score && j < maxIdx)) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(students[i], students[maxIdx]);
        }
    }
}
Read Input in main Function: The main function reads the number of students and their details (id and score).
int main() {
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].score;
    }
Sort the Students: The selectionSort function is called to sort the students based on their scores.
selectionSort(students, n);
Output the Sorted Students: The id of each student is printed in the sorted order.
for (const auto& student : students) {
    cout << student.id << endl;
}
return 0;

*/
#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    int score;
};

void selectionSort(vector<Student>& students, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].score > students[maxIdx].score || 
                (students[j].score == students[maxIdx].score && j < maxIdx)) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(students[i], students[maxIdx]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].score;
    }

    selectionSort(students, n);

    for (const auto& student : students) {
        cout << student.id << endl;
    }

    return 0;
}
/*
ลูกปัดจีนแดง (Fake Beads)
หลังจากที่หลวงปู่ทวีไชย ได้ปลุกเสกลูกปัดออกมา มีนักศึกษานำไปบูชาเป็นจำนวนมาก ซึ่งได้รับความ
นิยมเป็นจำนวนมาก เพราะทำข้อสอบได้คะแนนเยอะมากๆ นอกจากนั้นยังมีบุคคลที่มีชื่อเสียงเช่าไปบูชา เช่น
นักการเมืองคนดังนามแฝง อิ๊งอุ๊ง ที่ใช้ลูกปัดของหลวงปู่ ในขณะที่กำลังโหวตเลือกนายกรัฐมนตรี ทำให้ตนได้
รับเลือก เมื่อข่าวกระจายออกไปทำให้ลูกปัดนั้นขาดตลาดอย่างมาก รัฐบาลกิ่งปัก จึงใช้โอกาสนี้ในการผลิตของ
เลียนแบบเพื่อตีตลาดและขายส่งมายังไทย แต่เครื่องจักรในการเรียงลูกปัดนั้นมีปัญหาในการเรียงโดยที่ลูกปัด
นั้นต้องเรียงด้วยระยะห่างเท่าๆกัน แต่เครื่องจักรได้เรียงผิดโดยลูกปัดแต่ละลูกเรียงห่างไม่เท่ากัน โดยที่ในสาย
ลูกปัดที่ผลิตออกมามีระยะที่ถูกต้องคือระยะที่น้อยที่สุด เมื่อรัฐบาลกิ่งปักทราบเรื่อง จึงได้ให้คนงานจำนวน
มากจัดเรียงลูกปัดใหม่
โดยการจัดเรียงระยะลูกปัดนั้นลูกปัดลูกแรกจะไม่ถูกขยับ และลูกปัดลูกถัดไปจะมีระยะ min เรียงไป
เรื่อยๆ จนครบทุกลูก
จากตัวอย่าง มีลูกปัดทั้งหมด 5 ลูก อยู่ที่ตำแหน่ง 12, 17, 18, 21, 23 ตามลำดับ แล้วทำการหาระยะห่าง
ที่สั้นที่สุด ซึ่งคือ 1 จากนั้นทำการเลื่อนลูกปัดแต่ละลูกโดยที่ให้ลูกแรกอยู่ตำแหน่งเดิม ดังนั้นลูกปัดแต่ละลูกถูก
เลื่อน 0, 4, 4, 6, 7 หน่วย ตามลำดับ
สิ่งที่ต้องทำคือการรับจำนวนลูกปัดทั้งหมดจากผู้ใช้ และรับตำแหน่งของลูกปัดแต่ละลูก แล้วคำนวณหาว่าลูกปัดแต่ละลูกต้องทำการขยับเท่าไร เพื่อให้ได้ระยะห่างที่ถูกต้อง(min)
ข้อมูลนำเข้า (Input)
บรรทัด 1 จำนวนลูกปัด (n), 1 ≤ n ≤ 5, 000
บรรทัด 2 ตำแหน่งของลูกปัดลูกนั้นๆเป็นจำนวนเต็มบวก (pi) n จำนวน โดยที่ pi < pi+1
ข้อมูลส่งออก (Output)
บรรทัด 1 ระยะที่ลูกปัดแต่ละลูกต้องเลื่อน n ตัว
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input
10
1 4 5 10 13 15 18 22 25 30
Output
0 2 2 6 8 9 11 14 16 20
Input
5
45 60 70 72 80
Output
0 13 21 21 27
*/
/*
Plan
Read Input:
Read the number of beads n.
Read the positions of the beads into a vector.

Calculate Minimum Distance:
Calculate the minimum distance between consecutive beads.

Calculate and Print Movements:
For each bead, calculate its expected position based on the minimum distance.
Calculate the movement required to reach the expected position.
Print the movement for each bead.
<------------------------------------------------------------------------>
Pseudocode
Read Input:
Read integer n.
Initialize a vector positions of size n.
Loop i from 0 to n-1:
Read positions[i].

Calculate Minimum Distance:
Initialize min_dist to positions[1] - positions[0].
Loop i from 1 to n-2:
Update min_dist to the minimum of min_dist and positions[i + 1] - positions[i].

Calculate and Print Movements:
Loop i from 0 to n-1:
Calculate expected_position as positions[0] + i * min_dist.
Calculate movement as positions[i] - expected_position.
Print movement.
<------------------------------------------------------------------------>
Explanation
Reading Input:
The program starts by reading the number of beads n and their positions into a vector positions.

Calculating Minimum Distance:
The minimum distance between consecutive beads is calculated by iterating through the vector and finding the smallest difference between any two consecutive positions.

Calculating and Printing Movements:
For each bead, the expected position is calculated assuming the beads are evenly spaced by the minimum distance.
The movement required to reach this expected position is calculated and printed.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> positions(n);

    // Input the positions of the beads
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    // Calculate the minimum distance between consecutive beads
    int min_dist = positions[1] - positions[0];
    for (int i = 1; i < n - 1; i++) {
        min_dist = min(min_dist, positions[i + 1] - positions[i]);
    }

    // Calculate and print the movement for each bead
    for (int i = 0; i < n; i++) {
        int expected_position = positions[0] + i * min_dist;
        int movement = positions[i] - expected_position;
        cout << movement << " ";
    }
    cout << endl;

    return 0;
}
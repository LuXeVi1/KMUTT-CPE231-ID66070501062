/* บวกเลขง่าย ๆ การบวกเลขคือการนำจำนวนใดๆมารวมกัน ตัวอย่างเช่น 1 + 1 จะมีค่าเท่ากับ 2 หากจำนวนของตัวเลขที่นำมาบวกมีจำนวนเยอะ เราสามารถเขียนรูปของสัญลักษณ์ทางคณิตศาสตร์ได้ว่า
y =n∑i=1xi = x1 + x2 + · · · + xn
โดยที่ xi คือจำนวนใด ๆ
n คือจำนวนตัวเลขที่จะนำมาบวก
y คือผลรวม
หรือจะเรียกอีกอย่างว่า summation ซึ่งเขียนแทนด้วยสัญลักษณ์ Σ
ลำดับเลขคณิต หรือ Arithmetic progression เป็นลำดับของเลขที่เรียงกันโดยที่มีผลต่างของแต่ละลำดับเท่ากัน สามารถเขียนได้จาก
an = a1 + (n − 1)d
โดยที่ an คือเลขลำดับที่ n
a1 คือเลขลำดับที่ 1
d คือผลต่างร่วมของลำดับ
หากเราต้องการที่จะสร้าง list ของ Positive Number จาก 1 ถึง x ใดๆ เราสามารถเขียนได้จากสมการArithmetic Progression โดยที่ a1 และ d มีค่าเท่ากับ 1
จากคำนิยามที่กำหนดให้ด้านบน หากต้องการหาว่าจะต้องบวก Positive Number ตัวไหนบ้าง โดยที่ a1 = 1 และ ax = x เพื่อให้ได้ผลลัพธ์เท่ากับ y โดยที่เลขที่จะนำมาบวกกันนั้นไม่ซ้ำกัน เช่น x = 5 โดยที่ต้องการจะบวกเลขให้ได้ 12 จะได้
1,2,3,4,5 = 1+2+4+5
1,2,3,4,5 = 3+4+5
จากตัวอย่างนี้จะได้วิธีการเลือกตัวเลขทั้งหมด 2 แบบ อยากทราบว่าในวิธีการทั้งหมดนั้น ใช้จำนวนคู่หรือจำนวนคี่เท่าไร จาดตัวอย่าง จำนวนคู่ 3 จำนวน และ 4 จำนวนคี่
คำนวนหาจำนวนเลขคู่และเลขคี่ทั้งหมด จากวิธีการบวกเลข ตั้งแต่ 1 ถึง x ใดๆ เพื่อให้ได้คำตอบ y
ข้อมูลนำเข้า (Input)
บรรทัด 1 เลขสุดท้ายของลำดับ (x) โดยที่ 1 < x < 5000
บรรทัด 2 ผลรวมที่ต้องการคำนวณ (y) โดยที่ 1 ≤ y ≤ 10000
ข้อมูลส่งออก (Output)
บรรทัด 1 จำนวนคี่ ทั้งหมดที่เป็นไปได้ในการหาผลรวม
บรรทัด 2 จำนวนคู่ ทั้งหมดที่เป็นไปได้ในการหาผลรวม
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input
5
9
Output
5
3
Input
10
22
Output
76
72
Input
17
52
Output
4414
3931
*/

/*
Plan
Input Reading: Read the values of x and y from the input.
Initialization: Initialize counters for odd and even sums.
Generate Combinations: Use a nested loop to generate all possible combinations of numbers from 1 to x.
Check Sum: For each combination, check if the sum equals y.
Count Odd and Even: If the sum equals y, count the number of odd and even numbers in the combination.
Output Results: Print the counts of odd and even sums.
<------------------------------------------------------------------------>
Pseudocode
Read x and y.
Initialize odd_count and even_count to 0.
Loop through all combinations of numbers from 1 to x.
For each combination, calculate the sum.
If the sum equals y, count the odd and even numbers in the combination.
Increment odd_count or even_count based on the counts.
Print odd_count and even_count.
<------------------------------------------------------------------------>
Explanation
Input Reading: The program reads x and y from the standard input.
Initialization: A vector numbers is initialized with values from 1 to x.
Generate Combinations: The total number of combinations is 2^x. The program iterates through each combination using bitwise operations.
Check Sum: For each combination, the sum is calculated. If the sum equals y, the number of odd and even numbers in the combination is counted.
Count Odd and Even: The counts of odd and even numbers are accumulated.
Output Results: The counts of odd and even sums are printed.
*/

#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int x, int y, int& odd_count, int& even_count) {
    vector<int> numbers(x);
    for (int i = 0; i < x; ++i) {
        numbers[i] = i + 1;
    }

    int total_combinations = 1 << x; // 2^x combinations

    for (int i = 1; i < total_combinations; ++i) {
        int sum = 0;
        int odd = 0;
        int even = 0;

        for (int j = 0; j < x; ++j) {
            if (i & (1 << j)) {
                sum += numbers[j];
                if (numbers[j] % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
        }

        if (sum == y) {
            odd_count += odd;
            even_count += even;
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    int odd_count = 0;
    int even_count = 0;

    findCombinations(x, y, odd_count, even_count);

    cout << odd_count << endl;
    cout << even_count << endl;

    return 0;
}
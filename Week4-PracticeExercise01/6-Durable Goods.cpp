/*
ครุภัณฑ์แทงจำหน่่าย (Durable Goods)
ภาควิชาวิศวกรรมคอมพิวเตอร์ต้องการที่จะเคลียร์ของต่าง ๆ ที่อยู่ในภาควิชาที่เก็บทิ้งร้างมานานหลายปี
(ให้ลองนึกถึงห้อง CPE1118 (Embedded System Lab) ที่เมื่อก่อนรกซะนึกว่าเป็นห้องเก็บของนั่นแหละ)
โดยเอาครุภัณฑ์ออกไปแทงจำหน่ายให้กับหน่วยงานอื่น ๆ
เมื่อเอาครุภัณฑ์ต่าง ๆ ออกไปจำหน่ายให้กับหน่วยงานต่าง ๆ ปรากฏว่าหน่วยงานอื่น ๆ ได้ให้ราคาของ
ครุภัณฑ์ต่างกัน
สมมติว่า บอร์ด Basys 3 Artix-7 FPGA Trainer Board เป็นบอร์ดที่ใช้ในการเรียนวิชา CPE222 เมื่อปีที่
แล้ว ซึ่งปีนี้ไม่ได้ใช้แล้ว จึงนำมาจำหน่ายออกไป โดยหน่วยงานอื่น ๆ ตั้งราคาซื้อไว้ดังนี้
หน่วยงาน ราคาซื้อ (พันบาท)
ภาควิชาวิศวกรรมอิเล็กทรอนิกส์ (ENE) 3
ภาควิชาวิทยาการคอมพิวเตอร์ (CSS) 4
สำนักหอสมุด 1.4
หอหญิง 2
รร.ดรุณสิกขาลัย 1.3
Figure 1: บอร์ด Basys 3 Artix-7 FPGA
สังเกตได้ว่าหน่วยงานอื่น ๆ ให้ราคาต่างกัน ในกรณีนี้เราก็ควรที่จะเลือกจำหน่ายให้กับภาควิชาวิทยาการ
คอมพิวเตอร์ (CSS) ด้วยราคา 4 พันบาท
สมมติว่าเรามีครุภัณฑ์รอแทงจำหน่ายทั้งหมด 5 ชิ้น และมีหน่วยงานตั้งรับซื้อ 5 หน่วยงาน ราคารับซื้อ
ของแต่ละครุภัณฑ์และแต่ละหน่วยงานสรุปออกมาเป็นตารางดังนี้ (หน่วย: พันบาท)
ENE CSS หอสมุด หอหญิง ดรุณสิกขาลัย
บอร์ด Basys 3 Artix-7 FPGA 3 4 1.4 2 1.3
ตู้เก็บของเหล็กสนิมเขรอะ 1 0.7 2 3 0.2
จอแก้ว CRT ยี่ห้อ Acer 2 2.4 1 0.4 1
Digital Oscilloscope 9.5 2 1 0.6 3
โต๊ะไม้ 1 0.4 2 7 4
มีข้อกำหนดว่า ภาควิชาสามารถจำหน่ายครุภัณฑ์ให้กับหน่วยงานอื่นได้เพียงหน่วยงานละหนึ่งชิ้น (ไม่
สามารถขายจำหน่ายครุภัณฑ์ให้หน่วยงานอื่นตั้งแต่ 2 ชิ้นขึ้นไป) หากภาควิชาต้องการที่จะจำหน่ายครุภัณฑ์ให้
ได้เงินมากที่สุด ภาควิชาควรที่จะเลือกจำหน่ายครุภัณฑ์ให้กับหน่วยงานต่าง ๆ ต่อไปนี้
ครุภัณฑ์ หน่วยงานที่รับซื้อ ราคาขาย (พันบาท)
บอร์ด Basys 3 Artix-7 FPGA CSS 4
ตู้เก็บของเหล็กสนิมเขรอะ หอสมุด 2
จอแก้ว CRT ยี่ห้อ Acer ดรุณสิกขาลัย 1
Digital Oscilloscope ENE 9.5
โต๊ะไม้ หอหญิง 7
เมื่อเราขายให้หน่วยงานตามตาราง เงินที่เราจะได้ทั้งหมดคือ 23500 บาท ซึ่งมากที่สุดที่เป็นไปได้ในกรณี
นี้แล้ว
จงหาว่า หากภาควิชาต้องการแทงจำหน่ายครุภัณฑ์จำนวน n และมีหน่วยงานรับซื้อจำนวน n หน่วยงานเท่ากัน จงหาว่านักศึกษาสามารถเลือกครุภัณฑ์ไปจำหน่ายหน่วยงานอื่น ๆ ให้ได้เงินมากที่สุดกี่บาท (ตอบเป็นหน่วยพันบาท) ด
ข้อมูลนำเข้า (Input)
บรรทัด 1 จำนวนเต็ม n แทนจำนวนครุภัณฑ์และจำนวนหน่วยงาน โดยที่ 1 ≤ n ≤ 10
ตั้งแต่บรรทัดที่ 2
ถึง n + 1
จำนวนจริงบรรทัดละ n ตัว แทนราคาขายในหน่วยพันบาทของครุภัณฑ์ที่
หน่วยงานต่าง ๆ รับซื้อ (ดูตัวอย่างประกอบ)
ข้อมูลส่งออก (Output)
บรรทัด 1 เงินที่ได้มากที่สุดที่เป็นไปได้
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input Output
5
3 4 1.4 2 1.3
1 0.7 2 3 0.2
2 2.4 1 0.4 1
9.5 2 1 0.6 3
1 0.4 2 7 4
23.5
6
7 5 1 4 2 3
4 7 5 8 10 54
51 21 4 2 3 8
15 48 5 2 4 1
1 8 9 21 17 3
8 59 2 4 12 5
192
5
10 10 10 10 10
7 5 2 1 3
8 7 8 9 1
100 51 5 21 0.1
21 1 7 8 6
131
*/


/*
Plan
Input Reading: Read the size of the matrix n and then read the n x n matrix of prices.
Dynamic Programming Setup: Use a recursive function with memoization to calculate the maximum profit.
Recursive Function: Define a function maxProfit that takes the current item and a bitmask representing the departments already considered.
Base Case: If all items have been considered, return 0.
Memoization Check: If the result for the current bitmask is already computed, return it.
Recursive Calculation: Iterate over all departments and calculate the maximum profit by considering each department for the current item.
Memoization Storage: Store the computed result in the memoization map.
Output the Result: Call the recursive function starting from the first item and an empty bitmask, then print the result.
<------------------------------------------------------------------------>
Pseudocode
function maxProfit(item, mask):
    if item == n:
        return 0
    if mask is in memo:
        return memo[mask]

    max_val = 0
    for dept from 0 to n-1:
        if mask does not have dept bit set:
            max_val = max(max_val, prices[item][dept] + maxProfit(item + 1, mask with dept bit set))

    memo[mask] = max_val
    return max_val

main:
    read n
    initialize prices as n x n matrix
    for i from 0 to n-1:
        for j from 0 to n-1:
            read prices[i][j]

    result = maxProfit(0, 0)
    print result
<------------------------------------------------------------------------>
Explanation
Input Reading: The program starts by reading the integer n, which represents the size of the matrix. It then reads an n x n matrix of prices, where prices[i][j] represents the price of the i-th item in the j-th department.
Dynamic Programming Setup: The maxProfit function is defined to calculate the maximum profit using recursion and memoization. The function takes two parameters: item (the current item being considered) and mask (a bitmask representing which departments have already been considered).
Base Case: If all items have been considered (item == n), the function returns 0.
Memoization Check: If the result for the current bitmask is already computed and stored in the memo map, the function returns the stored result.
Recursive Calculation: The function iterates over all departments. For each department that has not been considered yet (checked using the bitmask), it calculates the profit by adding the price of the current item in that department to the result of the recursive call for the next item with the updated bitmask.
Memoization Storage: The computed result for the current bitmask is stored in the memo map to avoid redundant calculations.
Output the Result: The main function initializes the prices matrix and reads the input values. It then calls the maxProfit function starting from the first item and an empty bitmask. Finally, it prints the result.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int n;
vector<vector<double>> prices;
unordered_map<int, double> memo;

double maxProfit(int item, int mask) {
    if (item == n) return 0;
    if (memo.find(mask) != memo.end()) return memo[mask];

    double max_val = 0;
    for (int dept = 0; dept < n; ++dept) {
        if (!(mask & (1 << dept))) {
            max_val = max(max_val, prices[item][dept] + maxProfit(item + 1, mask | (1 << dept)));
        }
    }

    memo[mask] = max_val;
    return max_val;
}

int main() {
    cin >> n;
    prices.resize(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> prices[i][j];
        }
    }

    double result = maxProfit(0, 0);
    cout << result << endl;

    return 0;
}
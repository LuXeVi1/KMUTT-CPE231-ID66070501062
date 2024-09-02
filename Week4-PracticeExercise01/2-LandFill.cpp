/*
Land Fill
ภาควิชาวิศวกรรมคอมพิวเตอร์ ภายใต้การนำของอาจารย์กิจกรรม ดร.ทวีชัย ได้มีวิสัยทัศน์ในการขยาย
ภาควิชา ให้สามารถรองรับการเปิดหลักสูตรใหม่ โดยจะทำการรับนักศึกษาเพิ่มเป็น 985 คนต่อปี แต่เนื่องจาก
สถานที่ไม่เพียงพอต่อจำนวนคน จึงได้มีมติให้ย้ายภาควิชาไปตั้งอยู่ที่ วิทยาเขตบางขุนธูป ซึ่งมีลักษณะเป็นเขา
ทำให้ต้องมีการจัดสรรค์งบประมาณสำหรับการถมที่ ซึ่งได้ส่ง คุณวงศธร สังศิลปเวช หัวหน้าชำนาญการสำรวจ
ไปสำรวจและวัดความสูงของพื้นที่ (เมตร) เทียบกับระดับน้ำทะเล ต่อความยาว 1 เมตรใด ๆ
โดยตัวอย่างข้อมูลของดินคือความสูงในแต่ละช่วง 1 เมตร เช่น หากมีการสำรวจที่ความยาว 10 เมตร ได้
ข้อมูลว่า 1, 1, 3, 4, 6, 3, 2, 2, 3, 4 จะได้ตัวอย่างความสูงดังรูป
จากนั้นจะมีการนำดินมาถม ซึ่งดินที่จะมาถมแต่ละครั้งมีรูปแบบเหมือนกัน โดยมีตัวแปรดังนี้ l, m, r
โดยที่ l แทนความสูงของดินด้านซ้าย
m แทนความสูงของดินในตำแหน่งที่สูงที่สุด
r แทนความสูงของดินด้านขวาสุด (r < m)
โดยการไล่ระดับความสูงของดิน จาก l ไป m นั้น จะเพิ่มขึ้นทีละ 1 เมตร และระดับความสูง m ไป r นั้น
จะลดทีละ 1 เมตร เช่น 3, 6, 4 หมายความว่าดินนั้นมีความสูงฝั่งซ้าย 3 เพิ่มไปที่ละ 1 จนถึง 6 และจากนั้นลด
ความสูงที่ละ 1 จนถึง 4 ทำให้เมื่อวัดความยาวของดินจะได้ทั้งหมด 6 เมตร ดังรูป
เมื่อทราบความสูงของที่ดิน และรูปแบบของดินแล้ว สิ่งที่ต้องทำคือการนำดินที่ได้นั้นมาถมที่ดินที่มีอยู่เดิม
เพื่อให้ได้ความขรุขระ (rough) น้อยที่สุด ซึ่งคำนวนได้จาก
rough =n−1∑i=1|hi − hi+1|
โดย hi คือความสูงของที่ดินที่อาจจะผ่านการถมแล้ว หรือไม่มีการถมเกิดขึ้นก็ได้ ต่อความยาว 1 เมตรใดๆ
โดยการถมนั้นไม่สามารถที่จะถมตำแหน่งเดิมได้ คือ หากตำแหน่งของดินทั้ง ทั้งกองที่ถูกถมไปแล้ว ไม่
สามารถที่จะถมดินทับที่ตำแหน่งเดิมทั้งหมดได้ ดังตัวอย่างด้านล่างข้อกำหนดคือห้ามถมที่เกิดตำแหน่งของความสูงของภูเขาที่สำรวจ
ตัวอย่างการถมดินเบื้องต้นจากในตัวอย่างข้อมูลความยาวของที่ดินที่ทราบความสูงคือ 10 เมตร และแต่ละเมตรสูง 1, 1, 3, 2, 2, 3,
1, 2, 3, 4 ดินที่นำมาถมคือ l = 1, m = 3, r = 2 ซึ่งทำให้ดินที่มาถมนั้นครอบคลุมความยาว 4 เมตร โดยที่ความ
ยาวแต่ละ 1 เมตร สูง 1, 2, 3, 2 ตามลำดับ ซึ่งจากในตัวอย่างจะเป็นการถมดิน 2 ครั้งจากนั้นทำการคำนวณ
หาความขรุขระ และลองถมวิธีอื่นไปเรื่อย ๆ จนกว่าจะได้ความขรุขระน้อยที่สุด
งานของคุณ คือรับค่าระยะของที่ดินที่ทราบความสูง จากนั้นใส่ข้อมูลความสูงของดินที่ความยาว 1 เมตรใด ๆ ผู้ใช้ใส่ข้อมูลของดิน (l, m, r) จากนั้นนำดินที่ได้มาถมในที่ดินที่เราทราบความสูง และหาความขรุขระที่น้อยที่สุดจากรูป
แบบการถมดินที่เป็นไปได้ทั้งหมด ด้วยภาษา C++
ข้อมูลนำเข้า (Input)
บรรทัด 1 ความยาวของที่ดิน (n)
บรรทัด 2 ความสูงของที่ดินใน 1 เมตรใดๆ n ตัว
บรรทัด 3 l, m, r ซึ่งเป็น parameter ของดินที่จะถม
ข้อมูลส่งออก (Output)
บรรทัด 1 ความขรุขระที่น้อยที่สุด
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input
10
1 2 3 3 6 2 2 1 1 1
1 2 1
Output
20
Input
15
4 4 4 4 4 4 5 1 2 3 4 5 6 3 2
3 5 4
Output
12
*/

/*
Plan
Input Reading:
Read the length of the land (n).
Read the heights of the land for each meter (n values).
Read the parameters l, m, r for the soil to be filled.

Generate Soil Pattern:
Create a function to generate the soil pattern based on l, m, r.

Calculate Roughness:
Create a function to calculate the roughness of the land.

Fill Soil and Minimize Roughness:
Try filling the soil at every possible position and calculate the resulting roughness.
Keep track of the minimum roughness encountered.

Output the Minimum Roughness.
<------------------------------------------------------------------------>
Explanation
Input Reading:
The program reads the length of the land (n), the heights of the land, and the parameters l, m, r.

Generate Soil Pattern:
The generateSoilPattern function creates a vector representing the soil pattern based on l, m, r.

Calculate Roughness:
The calculateRoughness function computes the roughness of the land by summing the absolute differences between consecutive heights.

Fill Soil and Minimize Roughness:
The findMinimumRoughness function tries filling the soil at every possible position in the land and calculates the resulting roughness. It keeps track of the minimum roughness encountered.

Output:
The program outputs the minimum roughness found.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

vector<int> generateSoilPattern(int l, int m, int r) {
    vector<int> soil;
    for (int i = l; i <= m; ++i) {
        soil.push_back(i);
    }
    for (int i = m - 1; i >= r; --i) {
        soil.push_back(i);
    }
    return soil;
}

int calculateRoughness(const vector<int>& land) {
    int roughness = 0;
    for (size_t i = 0; i < land.size() - 1; ++i) {
        roughness += abs(land[i] - land[i + 1]);
    }
    return roughness;
}

int findMinimumRoughness(vector<int> land, const vector<int>& soil) {
    int n = land.size();
    int s = soil.size();
    int minRoughness = INT_MAX;

    for (int i = 0; i <= n - s; ++i) {
        vector<int> newLand = land;
        for (int j = 0; j < s; ++j) {
            newLand[i + j] = soil[j];
        }
        int roughness = calculateRoughness(newLand);
        minRoughness = min(minRoughness, roughness);
    }

    return minRoughness;
}

int main() {
    int n;
    cin >> n;

    vector<int> land(n);
    for (int i = 0; i < n; ++i) {
        cin >> land[i];
    }

    int l, m, r;
    cin >> l >> m >> r;

    vector<int> soil = generateSoilPattern(l, m, r);
    int minRoughness = findMinimumRoughness(land, soil);

    cout << minRoughness << endl;

    return 0;
}
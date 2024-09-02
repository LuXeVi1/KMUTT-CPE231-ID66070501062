/*
Antenna
False เป็นบริษัทโทรคมนาคมขนาดใหญ่ ที่กำลังจะทดสอบการติดตั้งเสาสัญญาณ โดยที่ False จะติดตั้ง
เสาสัญญาณแบบสุ่มในแต่ละพื้นที่ ซึ่งบริษัทต้องการให้ได้ประสิทธิภาพการส่งสัญญาณร่วมกันของเสาใด ๆ ดี
ที่สุด ซึ่งในการหาประสิทธิภาพการส่งสัญญาณระหว่างแต่ละเสา (p) คำนวณได้จาก
p = |a1 − a2|
|a1| + |a2| + |b1 − b2|
|b1| + |b2|
โดยที่ a แทนความสูงของเสาสัญญาณ และ b แทนความสูงของพื้นที่ติดตั้งเสา วัดจากระดับน้ำทะเลของ
เสานั้นๆ
บริษัทพบว่าประสิทธิภาพการส่งสัญญาณของแต่ละเสานั้นหาได้จากการค่าเฉลี่ยประสิทธิภาพของการส่ง
สัญญาณของเสานั้นๆ หากเสาไหนมีค่าเฉลี่ยน้อยที่สุดแสดงว่ามีประสิทธิภาพดีที่สุด
อยากทราบว่าหากต้องการรับค่าความสูงของเสาสัญญาณและความสูงของพื้นที่ติดตั้งเสาของแต่ละเสาจากนั้นทำการคำนวณหาว่าเสาไหนมีประสิทธิภาพการส่งสัญญาณดีที่สุด (mean น้อยที่สุด) โดยแสดงเป็นค่า a, b ของเสานั้นๆ
ข้อมูลนำเข้า (Input)
บรรทัด 1 จำนวนเสา (n) โดยที่ 1 < n < 500
บรรทัด 2 (a, b) แทนความสูงของเสาและความสูงของที่ตั้ง n จำนวน
ข้อมูลส่งออก (Output)
บรรทัด 1 ab ของเสานั้นที่ทำให้ได้ประสิทธิภาพการสื่อสารมากที่สุด
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input Output
3
1 2
5 6
3 4
Output
3 4
Input
5
1 1
6 12
16 7
9 10
20 8
Output
20 8
*/

/*
Plan
Define Structures and Functions:
Define a structure Antenna to hold the coordinates of an antenna.
Define a function calculateEfficiency to compute the efficiency between two antennas.

Read Input:
Read the number of antennas n.
Read the coordinates of each antenna into a vector.

Calculate Mean Efficiencies:
For each antenna, calculate the total efficiency with all other antennas.
Compute the mean efficiency for each antenna.

Find the Best Antenna:
Identify the antenna with the lowest mean efficiency.

Output the Result:
Print the coordinates of the antenna with the best signal efficiency.
<------------------------------------------------------------------------>
Pseudocode
Define Structures and Functions:
Define struct Antenna with int a and int b.
Define double calculateEfficiency(const Antenna& ant1, const Antenna& ant2):
Calculate numerator as the sum of absolute differences of a and b coordinates.
Calculate denominator as the sum of absolute values of a and b coordinates of both antennas.
Return numerator / denominator.

Read Input:
Read integer n.
Initialize a vector antennas of size n.
Loop i from 0 to n-1:
Read antennas[i].a and antennas[i].b.

Calculate Mean Efficiencies:
Initialize a vector meanEfficiencies of size n with 0.0.
Loop i from 0 to n-1:
Initialize totalEfficiency to 0.0.
Loop j from 0 to n-1:
If i is not equal to j:
Add calculateEfficiency(antennas[i], antennas[j]) to totalEfficiency.
Set meanEfficiencies[i] to totalEfficiency / (n - 1).

Find the Best Antenna:
Initialize bestAntennaIndex to 0.
Initialize minMeanEfficiency to the maximum possible double value.
Loop i from 0 to n-1:
If meanEfficiencies[i] is less than minMeanEfficiency:
Set minMeanEfficiency to meanEfficiencies[i].
Set bestAntennaIndex to i.

Output the Result:
Print antennas[bestAntennaIndex].a and antennas[bestAntennaIndex].b.
<------------------------------------------------------------------------>
Explanation
Structures and Functions:
The Antenna structure holds the coordinates of an antenna.
The calculateEfficiency function computes the efficiency between two antennas based on their coordinates.
Reading Input:
The number of antennas n is read from the input.
The coordinates of each antenna are read into a vector antennas.
Calculating Mean Efficiencies:
For each antenna, the total efficiency with all other antennas is calculated.
The mean efficiency for each antenna is computed by dividing the total efficiency by (n - 1).
Finding the Best Antenna:
The antenna with the lowest mean efficiency is identified by iterating through the meanEfficiencies vector.
Outputting the Result:
The coordinates of the antenna with the best signal efficiency are printed.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Antenna {
    int a;
    int b;
};

double calculateEfficiency(const Antenna& ant1, const Antenna& ant2) {
    double numerator = std::abs(ant1.a - ant2.a) + std::abs(ant1.b - ant2.b);
    double denominator = std::abs(ant1.a) + std::abs(ant2.a) + std::abs(ant1.b) + std::abs(ant2.b);
    return numerator / denominator;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Antenna> antennas(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> antennas[i].a >> antennas[i].b;
    }
    
    std::vector<double> meanEfficiencies(n, 0.0);
    
    for (int i = 0; i < n; ++i) {
        double totalEfficiency = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                totalEfficiency += calculateEfficiency(antennas[i], antennas[j]);
            }
        }
        meanEfficiencies[i] = totalEfficiency / (n - 1);
    }
    
    int bestAntennaIndex = 0;
    double minMeanEfficiency = std::numeric_limits<double>::max();
    
    for (int i = 0; i < n; ++i) {
        if (meanEfficiencies[i] < minMeanEfficiency) {
            minMeanEfficiency = meanEfficiencies[i];
            bestAntennaIndex = i;
        }
    }
    
    std::cout << antennas[bestAntennaIndex].a << " " << antennas[bestAntennaIndex].b << std::endl;
    
    return 0;
}
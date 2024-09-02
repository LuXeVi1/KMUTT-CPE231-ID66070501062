/*
นายกเซลส์แมน (The Salesman)
นายเสดถิน ทวีสา นายกรัฐมนตรีของประเทศทาลาลาลา (Thalalala) ได้ก้าวขึ้นสู่ตำแหน่งหลังจากได้รับ
ชัยชนะการเลือกตั้งแบบแลนด์สไลด์ ทีนี้นายเสดถินต้องการที่จะแก้ไขปัญหาวิกฤติเศรษฐกิจที่เป็นผลพวงมา
จากอดีต จึงต้องการเดินทางไปชักชวนต่างประเทศมาลงทุน
นายเสดถินให้คุณ ซึ่งเป็นนักศึกษาฝึกงานที่ทำเนียบรัฐบาลช่วยคำนวณค่าใช้จ่ายในการเดินทางไปต่าง
ประเทศ โดยเริ่มออกเดินทางจากประเทศทาลาลาลา ออกเดินทางไปอีก 5 ประเทศ ดังนี้ : สหราชอณาจักร,
สหรัฐอาหรับเอมิเรตส์, สหรัฐมเอริกา, สวีเดน. เดนมาร์ก
นายเสดถินได้ให้คุณไปศึกษาเที่ยวบินของแต่ละประเทศเพื่อวางแผนการเดินทาง คุณได้ไปศึกษาเที่ยวบิน
ต่าง ๆ ได้ออกมาทั้งหมด 12 เที่ยวบิน โดยสรุปเป็นตารางได้ดังนี้
เที่ยวบิน ค่าใช้จ่าย (หน่วย: แสนบาท)
ทาลาลาลา - สหราชอาณาจักร 6
ทาลาลาลา - สหรัฐอาหรับเอมิเรตส์ 4
ทาลาลาลา - สหรัฐอมริกา 8
สหราชอาณาจักร - สหรัฐอาหรับเอมิเรตส์ 2
สหราชอาณาจักร - สหรัฐอมริกา 3
สหราชอาณาจักร - สวีเดน 7
สหรัฐอาหรับเอมิเรตส์ - สหรัฐอมริกา 3
สหรัฐอาหรับเอมิเรตส์ - สวีเดน 6
สหรัฐอาหรับเอมิเรตส์ - เดนมาร์ก 10
สหรัฐอมริกา - สวีเดน 9
สหรัฐอมริกา - เดนมาร์ก 5
สวีเดน - เดนมาร์ก 9
ในแต่ละเที่ยวบิน ดังเช่นเที่ยวบินแรก (ทาลาลาลา-สหราชอาณาจักร) มีต่าใช้จ่าย 6 แสนบาท และสามารถ
ไป-กลับได้ หมายความว่าก็จะมีเที่ยวบินจาก (สหราชอาณาจักร-ทาลาลาลา) ด้วยค่าใช้จ่าย 6 แสนบาทเท่ากัน
เนื่องจากว่า นายเสดถินต้องการความสะดวกสบายขั้นสูงสุดเพื่อประสิทธิภาพและความผ่อนคลายในการ
ทำงานระหว่างบนเครื่องบิน นายเสดถินมีความเชื่อว่ายิ่งใช้ค่าใช้จ่ายกับเที่ยวบินมากแต่ไหนก็ยิ่งสบายมาก ๆ
นายเสดถินจึงต้องการให้คุณช่วยจัดลำดับของการบินไปประเทศต่าง ๆ โดยเริ่มจากประเทศทาลาลาลา จาก
นั้นก็เดินทางไปประเทศต่าง ๆ และสุดท้ายก็กลับมาที่ประเทศไทย โดยจะเดินทางไปประเทศนั้น ๆ เพียงหนึ่ง
ครั้งเท่านั้น โดยให้คุณจัดลำดับอย่างไรก็ได้ ให้ค่าใช้จ่ายในการบินมากที่สุดที่เป็นไปได้ ซึ่งในกรณีนี้คือ ทา
ลาลาลา→ สหราชอาณาจักร→ สหรัฐอาหรับเอมิเรตส์→ สวีเดน→ สหรัฐอมริกา→ ทาลาลาลา โดยใช้
งบประมาณทั้งหมด 4.4 ล้านบาท
หากนายเสดถินต้องการเดินทางไปประเทศทั้งหมด n ประเทศ และมีเส้นทางการบินทั้งหมด f เส้นทางการบิน ให้นักศึกษาหาเส้นทางที่ทำให้ค่าใช่จ่ายมากที่สุดที่เป็นไปได้ และคำนวณว่าเส้นทางดังกล่าวมีค่าใช้จ่ายเท่าใด ให้ตอบเป็นหน่วยแสนบาท
ข้อมูลนำเข้า (Input)
บรรทัด 1 จำนวนเต็ม n และ p แสดงจำนวนประเทศ (ไม่รวมทาลาลาลา) และจำนวน
เที่ยวบิน โดยที่ 1 ≤ n ≤ 10 และ p ≥ n + 1
ตั้งแต่บรรทัดที่ 2
ถึง f + 1
รหัสประเทศเป็นตัวย่อ 2 ตัว แสดงต้นทาง และปลายทาง ตามด้วยจำนวนเต็ม
x แสดงค่าใช้จ่ายในเที่ยวบินนั้น ๆ (ดูตัวอย่างประกอบ)
ข้อมูลส่งออก (Output)
บรรทัด 1 เส้นทางของเที่ยวบินที่ทำให้ค่าใช้จ่ายมากที่สุด โดยให้เป็นรหัสย่อประเทศ เว้น
ประเทศด้วยช่องว่าง 1 ตัว (ดูตัวอย่างประกอบ)
บรรทัด 2 ค่าใช้จ่ายที่มากที่สุดในหน่วยแสนบาท
ตัวอย่างข้อมูลนำเข้า ส่งออก (Examples of Input & Output)
Input
5 12
THA UK 6
THA UAE 4
THA USA 8
UK UAE 2
UK USA 3
UK SWE 7
UAE USA 3
UAE SWE 6
UAE DEN 10
USA SWE 9
USA DEN 5
SWE DEN 9
Output
THA UK UAE DEN SWE USA THA
44
Input
4 9
THA KOR 12
THA CHI 13
THA JAP 6
THA RUS 14
KOR CHI 3
KOR RUS 12
CHI JAP 15
CHI RUS 20
JAP RUS 14
Output
THA KOR RUS JAP CHI THA USA THA
66
*/


/*
Pseudocode
Read Input:
Read the number of countries n and the number of flights p.
Create a map flights to store the flights and their costs.

Read Flights:
For each flight, read the two countries u and v and the cost cost.
Store the cost in the flights map for both directions (u to v and v to u).

Read Countries:
Create a vector countries to store the names of the countries.
Read the names of the countries and store them in the countries vector.

Initialize Variables:
Create a vector visited to keep track of visited countries, initialized to false.
Initialize max_cost to 0 to keep track of the maximum cost.
Initialize best_route to store the best route.
Set start_country to the first country in the countries vector.

Find Best Route Using Permutations:
Use a do-while loop to generate all permutations of the countries (excluding the first country).
For each permutation:
Initialize current_cost to 0 and current_route to an empty vector.
Set current to start_country.
Mark the first country as visited and add it to current_route.
Perform a depth-first search to find the next unvisited country with a flight from the current country.
Update current_cost and current_route accordingly.
Mark the next country as visited and move to the next country.
After visiting all countries, check if there is a flight from the last country to the start country.
If there is, update current_cost and current_route.
If current_cost is greater than max_cost, update max_cost and best_route.
Mark all countries as unvisited for the next permutation.

Output the Best Route and Maximum Cost:
Print the best_route.
Print the max_cost.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // Read the number of countries and flights
    int n, p;
    cin >> n >> p;

    // Create a map to store the flights and their costs
    map<string, map<string, int>> flights;

    // Read the flights and their costs
    for (int i = 0; i < p; i++) {
        string u, v;
        int cost;
        cin >> u >> v >> cost;
        flights[u][v] = cost;
        flights[v][u] = cost;
    }

    // Create a vector to store the countries
    vector<string> countries;

    // Read the countries
    for (int i = 0; i < n; i++) {
        string country;
        cin >> country;
        countries.push_back(country);
    }

    // Create a vector to store the visited countries
    vector<bool> visited(n, false);

    // Initialize the maximum cost and the best route
    int max_cost = 0;
    vector<string> best_route;

    // Start from the first country
    string start_country = countries[0];

    // Perform depth-first search to find the best route
    do {
        // Initialize the current cost and the current route
        int current_cost = 0;
        vector<string> current_route;

        // Start from the first country
        string current = start_country;

        // Mark the first country as visited
        visited[0] = true;

        // Add the first country to the current route
        current_route.push_back(current);

        // Perform depth-first search
        for (int i = 0; i < n - 1; i++) {
            // Find the next unvisited country with a flight from the current country
            for (int j = 0; j < n; j++) {
                if (!visited[j] && flights[current][countries[j]] != 0) {
                    // Update the current cost and the current route
                    current_cost += flights[current][countries[j]];
                    current_route.push_back(countries[j]);

                    // Mark the next country as visited
                    visited[j] = true;

                    // Move to the next country
                    current = countries[j];

                    // Break the loop
                    break;
                }
            }
        }

        // Check if there is a flight from the last country to the start country
        if (flights[current][start_country] != 0) {
            // Update the current cost and the current route
            current_cost += flights[current][start_country];
            current_route.push_back(start_country);

            // Check if the current cost is greater than the maximum cost
            if (current_cost > max_cost) {
                // Update the maximum cost and the best route
                max_cost = current_cost;
                best_route = current_route;
            }
        }

        // Mark all countries as unvisited
        fill(visited.begin(), visited.end(), false);

    } while (next_permutation(countries.begin() + 1, countries.end()));

    // Print the best route and the maximum cost
    for (string country : best_route) {
        cout << country << " ";
    }
    cout << endl;
    cout << max_cost << endl;

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main() {
    string beads;
    char A, B;
    int p;
    
    // รับข้อมูลนำเข้า
    cin >> beads;
    cin >> A >> B;
    cin >> p;
    
    int n = beads.length();
    int count = 0;
    
    // วนลูปหา index ของตัวอักษร A (เริ่มต้น) และ B (สิ้นสุด)
    for (int i = 0; i < n; ++i) {
        if (beads[i] == A) { // หากเจอ A
            for (int j = i + p - 1; j < n; ++j) {
                if (beads[j] == B) { // หากเจอ B และความยาวไม่น้อยกว่า p
                    count++;
                }
            }
        }
    }
    
    // แสดงผลลัพธ์
    cout << count << endl;
    
    return 0;
}

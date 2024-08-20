#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

vector<bool> binary(int nBit, int n) {
    vector<bool> bin(nBit, 0);
    int i = nBit - 1;
    while (n && i >= 0) {
        bin[i] = n % 2;
        n /= 2;
        i--;
    }
    return bin;
}

bool isPalindrome(const string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter the name: ";
    cin >> input;
    int nBit = input.length();
    set<string> uniquePalindromes;

    for (int n = 1; n < (1 << nBit); n++) {
        vector<bool> bin = binary(nBit, n);
        string subStr = "";

        for (int i = 0; i < nBit; i++) {
            if (bin[i]) {
                subStr += input[i];
            }
        }

        if (subStr.length() > 1 && isPalindrome(subStr)) {
            uniquePalindromes.insert(subStr);
        }
    }

    cout << "Unique palindromes found: " << endl;
    for (const string &palindrome : uniquePalindromes) {
        cout << palindrome << endl;
    }

    cout << "Total number of unique palindromes: " << uniquePalindromes.size() << endl;

    return 0;
}
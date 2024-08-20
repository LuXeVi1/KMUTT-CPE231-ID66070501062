#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string &str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to convert a number to its binary representation with nBit length
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

// Function to calculate the hash value based on the number of palindromes
int calculateHashValue(const string &name) {
    int palindromeCount = 0;
    int len = name.length();

    // Generate all possible substrings using binary representation
    for (int n = 0; n < pow(2, len); n++) {
        vector<bool> bin = binary(len, n);
        vector<char> vStr;

        for (int i = 0; i < len; i++) {
            if (bin[i]) {
                vStr.push_back(name[i]);
            }
        }

        if (vStr.size() > 1) {
            string subStr(vStr.begin(), vStr.end());
            if (isPalindrome(subStr)) {
                palindromeCount++;
            }
        }
    }

    // Return the total number of palindromes
    return palindromeCount;
}

int main() {
    string name;
    cout << "Enter the name: ";
    cin >> name;

    // Calculate and display the hash value
    int hashValue = calculateHashValue(name);
    cout << "The memory position for the name is: " << hashValue << endl;

    return 0;
}

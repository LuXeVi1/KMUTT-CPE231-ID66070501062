#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

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

// Function to check if a string is a palindrome
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

    // Generate all possible substrings using binary representation
    for (int n = 1; n < (1 << nBit); n++) {
        vector<bool> bin = binary(nBit, n);
        string subStr = "";

        for (int i = 0; i < nBit; i++) {
            if (bin[i]) {
                subStr += input[i];
            }
        }

        // Check if the substring is a palindrome and has more than one character
        if (subStr.length() > 1 && isPalindrome(subStr)) {
            uniquePalindromes.insert(subStr); // Automatically handles duplicates
        }
    }

    // Output the unique palindromes found
    cout << "Unique palindromes found: " << endl;
    for (const string &palindrome : uniquePalindromes) {
        cout << palindrome << endl;
    }

    cout << "Total number of unique palindromes: " << uniquePalindromes.size() << endl;

    return 0;
}
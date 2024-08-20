#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// Function to convert an integer to a 9-bit binary vector
vector<bool> toBinary(int n, int nBit) {
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
bool isPalindrome(const string& str) {
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
    string input = "WONGSATORN";
    int nBit = input.length();
    set<string> uniquePalindromes;

    // Generate all possible 9-bit binary numbers
    for (int i = 1; i < (1 << nBit); i++) {
        vector<bool> bin = toBinary(i, nBit);

        // Form the substring based on the binary mask
        string subStr = "";
        for (int j = 0; j < nBit; j++) {
            if (bin[j]) {
                subStr += input[j];
            }
        }

        // Check if the substring is a palindrome and has more than one character
        if (subStr.length() > 1 && isPalindrome(subStr)) {
            uniquePalindromes.insert(subStr); // Automatically handles duplicates
        }
    }

    // Output the unique palindromes found
    cout << "Unique palindromes found: " << endl;
    for (const string& palindrome : uniquePalindromes) {
        cout << palindrome << endl;
    }

    cout << "Total number of unique palindromes: " << uniquePalindromes.size() << endl;

    return 0;
}

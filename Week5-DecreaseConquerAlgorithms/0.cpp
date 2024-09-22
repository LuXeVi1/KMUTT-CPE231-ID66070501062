#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>

const std::vector<long long> FACTORIALS = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};

long long findRank(const std::string& str) {
    size_t len = str.length();
    if (len < 3 || len > 11) {
        throw std::invalid_argument("Pattern length must be between 3 and 11");
    }

    std::unordered_set<char> uniqueChars(str.begin(), str.end());
    if (uniqueChars.size() != len) {
        throw std::invalid_argument("Pattern contains duplicate characters");
    }

    long long rank = 1;
    long long fact = FACTORIALS[len];
    std::vector<int> charCount(9, 1);

    for (size_t i = 0; i < len; ++i) {
        fact /= (len - i);
        int charIndex = str[i] - 'A';
        int rankValue = 0;

        for (int j = 0; j < charIndex; ++j) {
            rankValue += charCount[j];
        }

        rank += rankValue * fact;
        charCount[charIndex] = 0;
    }

    return rank;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    if (n < 3 || n > 11) {
        std::cerr << "Error: n must be between 3 and 11" << std::endl;
        return 1;
    }

    std::vector<std::string> passwords(m);
    for (size_t i = 0; i < m; ++i) {
        std::cin >> passwords[i];
        if (passwords[i].length() != n) {
            std::cerr << "Error: Password length must be " << n << std::endl;
            return 1;
        }
    }

    for (const std::string& password : passwords) {
        try {
            std::cout << findRank(password) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int findRank(std::string str) {
    int len = str.length();
    int rank = 1;
    int fact = factorial(len);

    std::vector<int> charCount(256, 0);

    for (int i = 0; i < len; ++i) {
        charCount[str[i]]++;
    }

    for (int i = 0; i < 256; ++i) {
        if (charCount[i] > 1) {
            std::cerr << "Error: String contains duplicate characters" << std::endl;
            return -1;
        }
    }

    for (int i = 0; i < len; ++i) {
        fact = fact / (len - i);
        int rankValue = 0;
        for (int j = 0; j < str[i]; ++j) {
            rankValue += charCount[j];
        }
        rank += rankValue * fact;
        charCount[str[i]] = 0;
    }

    return rank;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> passwords(m);

    for (int i = 0; i < m; ++i) {
        std::cin >> passwords[i];
    }

    for (const std::string& password : passwords) {
        std::cout << findRank(password) << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class LotteryChecker {
private:
    std::string text;
    std::string pattern;
    std::vector<int> badCharTable;

    void createBadCharTable() {
        int m = pattern.length();
        badCharTable = std::vector<int>(256, m);
        for (int i = 0; i < m - 1; ++i) {
            badCharTable[pattern[i]] = m - 1 - i;
        }
    }

public:
    LotteryChecker(const std::string& t, const std::string& p) : text(t), pattern(p) {
        createBadCharTable();
    }

    std::pair<bool, std::pair<int, int> > check() {
        int n = text.length();
        int m = pattern.length();
        int shifts = 0;
        int i = m - 1;

        while (i < n) {
            int k = 0;
            while (k < m && pattern[m - 1 - k] == text[i - k]) {
                ++k;
            }

            if (k == m) {
                return std::make_pair(true, std::make_pair(shifts, i - m + 1));
            }

            shifts++;
            i += badCharTable[text[i]];
        }

        return std::make_pair(false, std::make_pair(shifts, -1));
    }
};

int main() {
    int m, n;
    std::string text, pattern;

    std::cin >> m >> n;
    std::cin >> text >> pattern;

    LotteryChecker checker(text, pattern);
    std::pair<bool, std::pair<int, int> > result = checker.check();

    if (result.first) {
        std::cout << "YES " << result.second.first << " " << result.second.second << std::endl;
    } else {
        std::cout << "NO " << result.second.first << " " << result.second.second << std::endl;
    }

    return 0;
}
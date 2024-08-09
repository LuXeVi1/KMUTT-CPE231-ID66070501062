// Arkkhanirut tPandej 66070501062
// Testcase 2 11 28 68 38

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pots(n), plants(n);
    for(int i = 0; i < n; i++) {
        std::cin >> pots[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> plants[i];
    }

    std::sort(pots.begin(), pots.end(), std::greater<int>());
    std::sort(plants.begin(), plants.end(), std::greater<int>());

    std::vector<int> height_diff(n);
    for(int i = 0; i < n; i++) {
        height_diff[i] = std::abs(pots[i] - plants[i]);
    }

    std::sort(height_diff.begin(), height_diff.end());

    int smallest_diff = 0;
    for(int i = 1; i < n; i++) {
        smallest_diff += std::abs(height_diff[i] - height_diff[i-1]);
    }

    std::cout << smallest_diff << std::endl;

    return 0;
}
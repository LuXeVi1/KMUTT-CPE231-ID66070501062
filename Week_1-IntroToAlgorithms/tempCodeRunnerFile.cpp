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

    // Sort the pots and plants in descending order
    std::sort(pots.begin(), pots.end(), std::greater<int>());
    std::sort(plants.begin(), plants.end(), std::greater<int>());

    // Pair the pots and plants and calculate the height difference
    std::vector<int> height_diff(n);
    for(int i = 0; i < n; i++) {
        height_diff[i] = std::abs(pots[i] - plants[i]);
    }

    // Sort the height differences
    std::sort(height_diff.begin(), height_diff.end());

    // Calculate the smallest possible difference in tree height
    int smallest_diff = 0;
    for(int i = 1; i < n; i++) {
        smallest_diff += std::abs(height_diff[i] - height_diff[i-1]);
    }

    std::cout << smallest_diff << std::endl;

    return 0;
}
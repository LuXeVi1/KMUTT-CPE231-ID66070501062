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

    // Sort the pots and plants in ascending order
    std::sort(pots.begin(), pots.end());
    std::sort(plants.begin(), plants.end());

    // Pair the pots and plants and calculate the total height
    std::vector<int> total_height(n);
    for(int i = 0; i < n; i++) {
        total_height[i] = pots[i] + plants[i];
    }

    // Calculate the smallest possible difference in total height
    int smallest_diff = 0;
    for(int i = 1; i < n; i++) {
        smallest_diff += std::abs(total_height[i] - total_height[i-1]);
    }

    std::cout << smallest_diff << std::endl;

    return 0;
}
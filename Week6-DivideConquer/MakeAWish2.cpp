#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class MaxSubarrayFinder {
public:
    static int findMaxSum(const std::vector<int>& arr) {
        int maxSum = std::numeric_limits<int>::min();
        int currentSum = 0;

        for (const int& num : arr) {
            currentSum = std::max(num, currentSum + num);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int& num : arr) {
        std::cin >> num;
    }

    int result = MaxSubarrayFinder::findMaxSum(arr);
    std::cout << result << std::endl;

    return 0;
}
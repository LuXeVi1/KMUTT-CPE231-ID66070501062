#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<long long>> dp;
    std::vector<std::pair<int, int>> items;
    int numItems, maxMessiness;

    long long solve(int index, int remainingMessiness) {
        if (remainingMessiness < 0) return LLONG_MIN;
        if (index == numItems) return 0;

        if (dp[index][remainingMessiness] != -1) return dp[index][remainingMessiness];

        long long result = solve(index + 1, remainingMessiness);

        if (remainingMessiness >= items[index].first) {
            result = std::max(result,
                items[index].second + solve(index + 1, remainingMessiness - items[index].first));
        }

        dp[index][remainingMessiness] = result;
        return result;
    }

public:
    long long findMaxLuxury() {
        std::cin >> numItems;
        items.resize(numItems);

        for (int i = 0; i < numItems; ++i) {
            int itemMessiness, itemLuxury;
            std::cin >> itemMessiness >> itemLuxury;
            items[i] = std::make_pair(itemMessiness, itemLuxury);
        }

        std::cin >> maxMessiness;

        dp.assign(numItems + 1, std::vector<long long>(maxMessiness + 1, -1));

        return solve(0, maxMessiness);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution solution;
    std::cout << solution.findMaxLuxury() << std::endl;

    return 0;
}
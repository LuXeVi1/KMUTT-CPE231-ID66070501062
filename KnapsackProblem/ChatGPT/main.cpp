#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "algorithmA/algorithmA.h"
#include "algorithmB/algorithmB.h"
#include "algorithmC/algorithmC.h"

void readInput(const std::string& filename, int& capacity, std::vector<int>& values, std::vector<int>& weights) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    int n;
    infile >> capacity >> n;
    values.resize(n);
    weights.resize(n);
    for (int i = 0; i < n; ++i) {
        infile >> values[i] >> weights[i];
    }
    infile.close();
}

int main() {
    std::string inputFile = "input.txt";
    int capacity;
    std::vector<int> values, weights;

    readInput(inputFile, capacity, values, weights);

    // Greedy
    auto startA = std::chrono::high_resolution_clock::now();
    double resultA = knapsackGreedy(capacity, values, weights);
    auto endA = std::chrono::high_resolution_clock::now();
    std::cout << "Algorithm A (Greedy): Max Value = " << resultA
              << " (Execution Time: "
              << std::chrono::duration<double>(endA - startA).count() << "s)" << std::endl;

    // Dynamic Programming
    auto startB = std::chrono::high_resolution_clock::now();
    int resultB = knapsackDP(capacity, values, weights);
    auto endB = std::chrono::high_resolution_clock::now();
    std::cout << "Algorithm B (DP): Max Value = " << resultB
              << " (Execution Time: "
              << std::chrono::duration<double>(endB - startB).count() << "s)" << std::endl;

    // Branch and Bound
    auto startC = std::chrono::high_resolution_clock::now();
    int resultC = knapsackBranchAndBound(capacity, values, weights);
    auto endC = std::chrono::high_resolution_clock::now();
    std::cout << "Algorithm C (Branch and Bound): Max Value = " << resultC
              << " (Execution Time: "
              << std::chrono::duration<double>(endC - startC).count() << "s)" << std::endl;

    return 0;
}

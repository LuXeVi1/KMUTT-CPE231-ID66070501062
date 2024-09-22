#include <iostream>
#include <vector>
#include <algorithm>

void flip(std::vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {
        std::swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

int findMax(const std::vector<int>& arr, int n) {
    int maxIndex = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMax(arr, currSize - 1);

        if (maxIndex != currSize - 1) {
            flip(arr, maxIndex);

            flip(arr, currSize - 1);
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    pancakeSort(arr);

    printArray(arr);

    return 0;
}

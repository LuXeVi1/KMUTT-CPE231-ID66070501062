#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

int quickSelect(std::vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k) {
        return arr[pivotIndex];
    }
    else if (pivotIndex > k) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    }
    else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    int n, k;
    
    std::cin >> n;

    std::vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> k;
    k--;

    int result = quickSelect(arr, 0, n - 1, k);

    std::cout << result << std::endl;

    return 0;
}

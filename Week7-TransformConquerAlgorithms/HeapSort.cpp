#include <iostream>
#include <vector>

void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    for (int i = 0; i < n / 2; i++)
        std::swap(arr[i], arr[n - 1 - i]);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    heapSort(arr);

    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
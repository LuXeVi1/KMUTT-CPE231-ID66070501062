#include <iostream>
#include <vector>

// Function to heapify the subtree rooted at index i in a min-heap
void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i;  // Initialize the smallest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root, swap it and continue heapifying
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min-heap from the input array
void buildMinHeap(std::vector<int>& arr) {
    int n = arr.size();

    // Start heapifying from the last non-leaf node to the root
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Function to sort the array using heap sort (min-heap)
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build the min-heap
    buildMinHeap(arr);

    // Step 2: Print the array after building the min heap (required by the problem)
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    // Step 3: Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (smallest element) to the end
        std::swap(arr[0], arr[i]);

        // Call minHeapify on the reduced heap
        minHeapify(arr, i, 0);
    }

    // Step 4: Reverse the array to get it in descending order
    for (int i = 0; i < n / 2; i++) {
        std::swap(arr[i], arr[n - 1 - i]);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Perform heap sort
    heapSort(arr);

    // Print the sorted array (in descending order)
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}

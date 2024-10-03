#include <iostream>
#include <vector>

using namespace std;

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

void initializeMinHeap(vector<int>& arr) {
    int n = arr.size();
    cout << "Results from the first Min Heapify session of your code: ";
    for (int i = n / 2 - 1; i >= 0; --i)
        minHeapify(arr, n, i);

    // Print the modified array
    cout << endl;
}

void heapSort(vector<int>& arr) {
    initializeMinHeap(arr);

    for (int i = arr.size() - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0); // Removed the unnecessary argument 'i'
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}

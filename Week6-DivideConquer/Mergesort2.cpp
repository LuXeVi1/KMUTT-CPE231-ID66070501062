#include <iostream>
#include <vector>
#include <algorithm>

class MergeSort {
private:
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        std::copy(temp.begin(), temp.end(), arr.begin() + left);
    }

    static void mergeSortHelper(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSortHelper(arr, left, mid);
            mergeSortHelper(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

public:
    static void sort(std::vector<int>& arr) {
        mergeSortHelper(arr, 0, arr.size() - 1);
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int& num : arr) {
        std::cin >> num;
    }

    MergeSort::sort(arr);

    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
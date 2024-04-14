#include <iostream>
#include <vector>

// Linear Search Function
// Complexity: O(n), Omega(1), Theta(n) on average
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i; // Target found, best case Omega(1)
        }
    }
    return -1; // Target not found, worst case O(n)
}

// Binary Search Function
// Complexity: O(log n), Omega(1), Theta(log n)
int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid; // Target found, best case Omega(1)
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Target not found, worst case O(log n)
}

int main() {
    std::vector<int> data = {10, 20, 5, 30, 25};

    // Testing linear search
    int target = 30;
    int index = linearSearch(data, target);
    if (index != -1) std::cout << "Linear Search: Element found at index " << index << std::endl;
    else std::cout << "Linear Search: Element not found." << std::endl;

    // Testing binary search - Array must be sorted
    std::vector<int> sortedData = {5, 10, 20, 25, 30};
    index = binarySearch(sortedData, 0, sortedData.size() - 1, target);
    if (index != -1) std::cout << "Binary Search: Element found at index " << index << std::endl;
    else std::cout << "Binary Search: Element not found." << std::endl;

    return 0;
}

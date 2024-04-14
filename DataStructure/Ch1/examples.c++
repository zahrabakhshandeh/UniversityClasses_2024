#include <iostream>
#include <vector>

// O(1) - Constant Time Complexity
int getFirstElement(const std::vector<int>& arr) {
    if (arr.empty()) return -1; // Handle empty array
    return arr[0];
}

// O(n) - Linear Time Complexity
int sumArray(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// O(n^2) - Quadratic Time Complexity
bool hasDuplicates(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// O(n^3) - Cubic Time Complexity
void threeNestedLoops(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                count++;
            }
        }
    }
    std::cout << "Count: " << count << std::endl;
}

// O(n^4) - Quartic Time Complexity
void fourNestedLoops(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    count++;
                }
            }
        }
    }
    std::cout << "Count: " << count << std::endl;
}

// O(2^n) - Exponential Time Complexity
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


/*
                            fibonacci(4)
                       /           \
               fibonacci(3)         fibonacci(2)
              /           \          /       \
      fibonacci(2)     fibonacci(1) fibonacci(1) fibonacci(0)
      /       \          (returns 1) (returns 1) (returns 0)
fibonacci(1) fibonacci(0)
(returns 1)  (returns 0)

*/
int main() {
    std::vector<int> data = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 5; // Example size for n
    
    // Demonstrating O(1)
    std::cout << "First element: " << getFirstElement(data) << std::endl;
    
    // Demonstrating O(n)
    std::cout << "Sum of array: " << sumArray(data) << std::endl;
    
    // Demonstrating O(n^2)
    std::cout << "Has duplicates: " << (hasDuplicates(data) ? "Yes" : "No") << std::endl;
    
    // Demonstrating O(n^3)
    threeNestedLoops(n);
    
    // Demonstrating O(n^4)
    fourNestedLoops(n);
    
    // Demonstrating O(2^n)
    std::cout << "Fibonacci of " << n << ": " << fibonacci(n) << std::endl;
    
    return 0;
}
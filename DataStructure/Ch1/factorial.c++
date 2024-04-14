#include <iostream>
// 4! ------> 4 * 6 = 24
// 3! -----> 3 * 2 = 6
// 2! -------> 2 * 1 = 2
// 1! -------> 1 ==========> end point
int factorial(int n) {
    if (n == 0) {  
        return 1;
    } else {
        return n * factorial(n - 1);  // 4 * f(3)
    }
}
/*
    factorial(4)
    │
    └── 4 * factorial(3)
        │
        └── 3 * factorial(2)
            │
            └── 2 * factorial(1)
                │
                └── 1 * factorial(0)
                    │
                    └── 1  (base case)

*/

/*
    T(n) = T(n - 1) + c
     = (T(n - 2) + c) + c
     = ((T(n - 3) + c) + c) + c
     ...
     = T(0) + n * c =====> O(n)

*/
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "The factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}

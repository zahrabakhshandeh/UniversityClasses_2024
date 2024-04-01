#include <iostream>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    int arr[5]; // Declaration
    int arrInitialized[5] = {1, 2, 3, 4, 5}; // Declaration and initialization

    // 2. Accessing Elements
    arr[0] = 10;
    cout << "Third element: " << arrInitialized[2] << endl; // Access and print the third element

    // 3. Loop 
    cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        cout << arrInitialized[i] << " "; // Print each element
    }
    cout << endl;

    // 4. Multidimensional Arrays
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; // A 2x3 matrix
    cout << "Result: " << matrix[1][2] << endl; // Access and print

    // 5. Array Size
    int size = sizeof(arrInitialized) / sizeof(arrInitialized[0]);
    cout << "Array size: " << size << endl;
    return 0;
}

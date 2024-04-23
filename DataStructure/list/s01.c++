#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector of 10 integers initialized to 0
    vector<int> v(10, 0);
    int list1 = {0, 0, 0, 0}
    

    // Empty
    cout << "Is the vector empty?  " << v.empty() << endl;            
    
    // Print the size of the vector
    cout << "Size of vector:  " << v.size() << endl;

    // Assign new values
    v[0] = 42;   // First element
    v[9] = 91;   // Last element
    
    // Loop through the vector 
    for (int k = 0; k < 10; ++k) {
        cout << "v[" << k << "] = " << v[k] << endl;
    }

    return 0;
}

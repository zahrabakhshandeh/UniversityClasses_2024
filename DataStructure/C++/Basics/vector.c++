#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    vector<int> vec; 
    vector<int> vecInitialized = {1, 2, 3, 4, 5}; // Declaration and initialization

    // 2. Adding Elements
    vec.push_back(10); 
    vecInitialized.push_back(6); 

    // 3. Access
    cout << "Third element: " << vecInitialized[2] << endl; 

    // 4. LOOP
    cout << "Vector elements: ";
    for(int i = 0; i < vecInitialized.size(); i++) {
        cout << vecInitialized[i] << " "; // Using index
    }
    cout << endl;
    cout << "Elements: ";
    for(auto& element : vecInitialized) {
        cout << element << " "; 
    }
    cout << endl;

    // 5. Remov
    vecInitialized.pop_back(); 
    vecInitialized.erase(vecInitialized.begin() + 2); 

    // 6. Edit
    vecInitialized[1] = 20; 

    // 7. Vector Size
    cout << "Vector size: " << vecInitialized.size() << endl;

    // 8. Search
    int searchFor = 20;
    bool found = false;
    for(int i = 0; i < vecInitialized.size(); ++i) {
        if (vecInitialized[i] == searchFor) {
            cout << "Element " << searchFor << " found at index " << i << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }

    return 0;
}

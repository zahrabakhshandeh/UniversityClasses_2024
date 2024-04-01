#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables
    int intVar1 = 10;
    float floatVar1 = 3.14;
    char charVar1 = 'A';
    string strVar1 = "Hello, World!";
    bool boolVar1 = true;

    int intVar2;
    float floatVar2;
    char charVar2;
    string strVar2;
    bool boolVar2;

    // User input
    cout << "Enter an integer: ";
    cin >> intVar2;
    cout << "Enter a floating number: ";
    cin >> floatVar2;
    cout << "Enter a character: ";
    cin >> charVar2;
    cout << "Enter a string: ";
    cin.ignore(); 
    getline(cin, strVar2); 
    cout << "Enter a boolean value (0 for false, 1 for true): ";
    cin >> boolVar2;

    // Output variables
    cout << "You entered integer: " << intVar2 << ", float: " << floatVar2 << ", char: " << charVar2 << endl;
    cout << "String: " << strVar2 << ", Boolean: " << boolVar2 << endl;

    // If statement
    if (intVar2 > 5) {
        cout << intVar2 << " is greater than 5" << endl;
    } else {
        cout << intVar2 << " is not greater than 5" << endl;
    }

    // For loop
    cout << "For loop from 0 to 4: ";
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
    }
    cout << endl;

    // While loop
    cout << "While loop from 5 to 9: ";
    int i = 5;
    while (i < 10) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // Do-While loop
    cout << "Do-While loop from 10 to 14: ";
    i = 10;
    do {
        cout << i << " ";
        i++;
    } while (i < 15);
    cout << endl;

    // Example
    cout << "Odd numbers between 1 and 10: ";
    for (int j = 1; j <= 10; ++j) {
        if (j % 2 != 0) { // If 'j' is odd
            cout << j << " ";
        }
    }
    cout << endl;

    return 0;
}

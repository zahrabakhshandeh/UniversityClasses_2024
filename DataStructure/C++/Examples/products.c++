#include <iostream>
using namespace std;

const int MAX_PRODUCTS = 10;
string productNames[MAX_PRODUCTS];
double productPrices[MAX_PRODUCTS];
int productCount = 0;

bool isProductNameUnique(string name) {
    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name){
        	return false;
        } 
    }
    return true;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory full. Cannot add more products.\n";
        return;
    }
    cout << "Enter product name: ";
    string name;
    cin >> name;
    if (!isProductNameUnique(name)) {
        cout << "Product name must be unique. Please try again.\n";
        return;
    }
    cout << "Enter product price: ";
    double price;
    cin >> price;
    productNames[productCount] = name;
    productPrices[productCount] = price;
    productCount++;
    cout << "Product added successfully.\n";
}

int findProductIndex(string name) {
    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name) return i;
    }
    return -1; 
}

void editProduct() {
    cout << "Enter product name to edit: ";
    string name;
    cin >> name;
    int index = findProductIndex(name);
    if (index == -1) {
        cout << "Product not found.\n";
        return;
    }
    cout << "Enter new price for " << productNames[index] << ": ";
    cin >> productPrices[index];
    cout << "Product price updated successfully.\n";
}

//p = [-, -, -, -]
// max_count = 4
// count = 0
// p[0] = 200
// [200, 4, 6, 8]
// count = 4
void removeProduct() {
    cout << "Enter product name to remove: ";
    string name;
    cin >> name;
    int index = findProductIndex(name);
    // productNames = ["p1", "p3", "p4", -]
    // productPrices = [12.6, 36.6, 3.7, -]
    if (index == -1) {
        cout << "Product not found.\n";
        return;
    }
    // index = 1
    for (int i = index; i < productCount - 1; i++) {
        productNames[i] = productNames[i + 1];
        productPrices[i] = productPrices[i + 1];
    }
    productCount--;
    cout << "Product removed successfully.\n";
}

void displayProducts() {
    if (productCount == 0) {
        cout << "No products in the inventory.\n";
        return;
    }
    cout << "Products in inventory:\n";
    for (int i = 0; i < productCount; i++) {
        cout << i + 1 << ". " << productNames[i] << " - $" << productPrices[i] << endl;
    }
}

void displayMenu() {
    cout << "\n--- Shop Management System ---\n";
    cout << "1. Add Product\n";
    cout << "2. Display Products\n";
    cout << "3. Edit Product\n";
    cout << "4. Remove Product\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                editProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
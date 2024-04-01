#include <iostream>
#include <vector>
using namespace std;

vector<string> productNames;
vector<double> productPrices;

bool isProductNameUnique(string name) {
    for (string productName : productNames) {
        cout << productName<<endl;
        if (productName == name) return false;
    }
    return true;
}

void addProduct() {
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
    productNames.push_back(name);
    productPrices.push_back(price);
    cout << "Product added successfully.\n";
}

int findProductIndex(string name) {
    for (int i = 0; i < productNames.size(); ++i) {
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

void removeProduct() {
    cout << "Enter product name to remove: ";
    string name;
    cin >> name;
    int index = findProductIndex(name);
    if (index == -1) {
        cout << "Product not found.\n";
        return;
    }
    // Remove the product by shifting elements to the left
    productNames.erase(productNames.begin() + index);
    productPrices.erase(productPrices.begin() + index);
    cout << "Product removed successfully.\n";
}

void displayProducts() {
    if (productNames.empty()) {
        cout << "No products in the inventory.\n";
        return;
    }
    cout << "Products in inventory:\n";
    for (int i = 0; i < productNames.size(); ++i) {
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

#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
};

vector<Product> products;

bool isProductNameUnique(string name) {
    for (Product product : products) {
        cout << product.name;
        if (product.name == name) return false;
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
    products.push_back({name, price});
    cout << "Product added successfully.\n";
}

int findProductIndex(string name) {
    for (int i = 0; i < products.size(); ++i) {
        if (products[i].name == name) return i;
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
    cout << "Enter new price for " << products[index].name << ": ";
    double newPrice;
    cin >> newPrice;
    products[index].price = newPrice;
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

    products.erase(products.begin() + index);
    cout << "Product removed successfully.\n"<<index;
}

void displayProducts() {
    if (products.empty()) {
        cout << "No products in the inventory.\n";
        return;
    }
    cout << "Products in inventory:\n";
    cout << products.size();
    for (int i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << endl;
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

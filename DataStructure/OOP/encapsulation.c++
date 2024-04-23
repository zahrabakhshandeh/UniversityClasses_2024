#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;    // Private attribute (sensitive)
    int id;         // Private attribute (sensitive)

public:
    double grade;   // Public attribute

private:
    // Private method for internal processing
    void printInternalInfo() const {
        cout << "Internal Check: Name - " << name << ", ID - " << id << endl;
    }

public:
    // Constructor to initialize the student data
    Student(string initName, int initId, double initGrade)
        : name(initName), id(initId), grade(initGrade) {
        cout << "Student created: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student destroyed: " << name << endl;
    }

    // Setter methods (public for name and ID, not needed for grade since it's public)
    void setName(string newName) {
        name = newName;
    }

    void setId(int newId) {
        id = newId;
    }

    // Getter methods (public for name and ID, not needed for grade since it's public)
    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    // Public method to display information
    void displayInfo() {
        cout << "Student Name: " << getName()  // Using getters within the class for private data
             << ", ID: " << getId()
             << ", Grade: " << grade  // Direct access since it's public
             << endl;
    }

    // Public method to perform a private check
    void performInternalCheck() {
        printInternalInfo();
    }
};

int main() {
    // Creating an instance of Student with the constructor
    Student student1("Ali", 123456, 88.5);
    student1.displayInfo(); // Using the dot operator

    // Modifying student1's data using setters
    student1.setName("Sara");
    student1.setId(654321);
    student1.grade = 91.5;  // Directly setting public attribute
    student1.displayInfo(); // Displaying updated info

    // Perform internal checks using a public method that calls a private method
    student1.performInternalCheck();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int id;
    double grade;

    // Constructor to initialize the student data
    Student(const string &initName, int initId, double initGrade)
        : name(initName), id(initId), grade(initGrade) {
        cout << "Student created: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student destroyed: " << name << endl;
    }

    // Method to display information
    void displayInfo() {
        cout << "Student Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

int main() {
    // Creating an instance of Student with the constructor
    Student student1("OBJ1", 123456, 88.5);
    student1.displayInfo(); // Using the dot operator

    // Creating a pointer to an instance of Student with the constructor
    Student *student2 = new Student("OBJ2", 654321, 92.5);
    student2->displayInfo(); // Using the arrow operator

    // Cleaning up dynamically allocated memory
    delete student2;

    // Note: student1's destructor will be called automatically when it goes out of scope

    return 0;
}

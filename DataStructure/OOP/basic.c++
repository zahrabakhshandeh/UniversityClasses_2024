#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;  
    int id;       
    double grade; 

    void displayInfo() {
        cout << "Student Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

int main() {
    // Instance of Student
    Student student1;
    student1.name = "John Doe";
    student1.id = 123456;
    student1.grade = 88.5;
    cout << student1.name;
    student1.displayInfo(); // Using the dot operator

    // Pointer to an instance of Student
    Student *student2 = new Student;
    student2->name = "Jane Doe";
    student2->id = 654321;
    student2->grade = 92.5;
    student2->displayInfo(); // Using the arrow operator

    delete student2; // Cleaning up dynamically allocated memory

    return 0;
}


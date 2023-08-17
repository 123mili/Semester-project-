#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    double marks;

    void input() {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() const {  // Changed to a const member function
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    const int maxStudents = 10;
    vector<Student> students;

    int choice;
    do {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (students.size() < maxStudents) {
                    Student newStudent;
                    newStudent.input();
                    students.push_back(newStudent);
                    cout << "Student added successfully!\n";
                } else {
                    cout << "Database is full. Cannot add more students.\n";
                }
                break;

            case 2:
                if (students.size() == 0) {
                    cout << "No students in the database.\n";
                } else {
                    cout << "\nStudent Information:\n";
                    for (const Student& student : students) {
                        student.display();  // Now works with const objects
                        cout << "------------------------\n";
                    }
                }
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}


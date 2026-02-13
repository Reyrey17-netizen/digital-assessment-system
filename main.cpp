#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Week 1: Implement Student class [cite: 55]
class Student {
private:
    string name;
    string indexNumber;

public:
    Student(string n, string id) : name(n), indexNumber(id) {}

    // Function to display student details [cite: 39]
    void display() const {
        cout << "Index: " << indexNumber << " | Name: " << name << endl;
    }

    // Getter for searching by index 
    string getIndex() const { return indexNumber; }
};

int main() {
    vector<Student> studentList;
    int choice;

    // Week 1: Build menu-driven program flow [cite: 28, 62]
    do {
        cout << "\n--- Digital Attendance System ---" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, id;
            cout << "Enter Student Name: ";
            cin.ignore(); // Clear buffer
            getline(cin, name);
            cout << "Enter Index Number: ";
            cin >> id;

            // Register students [cite: 38]
            studentList.push_back(Student(name, id));
            cout << "Student registered successfully!" << endl;

        }
        else if (choice == 2) {
            // View all registered students [cite: 39]
            cout << "\n--- Registered Students ---" << endl;
            for (const auto& s : studentList) {
                s.display();
            }
        }
        

        // Inside your main function, add this to your menu options
        else if (choice == 3) {
            string searchId;
            bool found = false;
            cout << "Enter Index Number to search: ";
            cin >> searchId;

            for (const auto& s : studentList) {
                if (s.getIndex() == searchId) {
                    cout << "Student Found:" << endl;
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Index " << searchId << " not found." << endl;
            }
        }
      
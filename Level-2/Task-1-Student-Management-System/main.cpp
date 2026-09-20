#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

int main() {

    int n;

    cout << "How many students do you want to enter? ";
    cin >> n;

    vector<Student> students(n);

    // Enter student information
    for (int i = 0; i < n; i++) {

        cout << "\nEnter details for student " << i + 1 << ":" << endl;

        cout << "ID: ";
        cin >> students[i].id;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Grade: ";
        cin >> students[i].grade;
    }

    // Display all students
    cout << "\n--- Student List ---" << endl;

    float totalGrade = 0;

    for (int i = 0; i < n; i++) {

        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Grade: " << students[i].grade << endl;

        totalGrade += students[i].grade;
    }

    // Calculate average grade
    float averageGrade = totalGrade / n;

    cout << "\nAverage Grade: " << averageGrade << endl;

    // Search for a student by ID
    int searchId;
    bool found = false;

    cout << "\nEnter student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < n; i++) {

        if (students[i].id == searchId) {

            cout << "\nStudent found!" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Grade: " << students[i].grade << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }

    // Find student with the highest grade
    int highestIndex = 0;

    for (int i = 1; i < n; i++) {

        if (students[i].grade > students[highestIndex].grade) {
            highestIndex = i;
        }
    }

    cout << "\n--- Highest Grade ---" << endl;
    cout << "Student: " << students[highestIndex].name << endl;
    cout << "Grade: " << students[highestIndex].grade << endl;

    return 0;
}
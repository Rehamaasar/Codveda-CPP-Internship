#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int choice;
    string fileName;
    string content;

    do {

        cout << "\n===== File System Simulation =====" << endl;
        cout << "1. Create and write to a file" << endl;
        cout << "2. Read a file" << endl;
        cout << "3. Delete a file" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 1) {

            cout << "Enter file name: ";
            cin >> fileName;

            cout << "Enter text to save: ";
            cin.ignore();
            getline(cin, content);

            ofstream file(fileName);

            if (file.is_open()) {

                file << content;
                file.close();

                cout << "File created successfully." << endl;
            }
            else {
                cout << "Error creating file." << endl;
            }
        }

        else if (choice == 2) {

            cout << "Enter file name: ";
            cin >> fileName;

            ifstream file(fileName);

            if (file.is_open()) {

                cout << "\nFile content:" << endl;

                while (getline(file, content)) {
                    cout << content << endl;
                }

                file.close();
            }
            else {
                cout << "File not found." << endl;
            }
        }

        else if (choice == 3) {

            cout << "Enter file name: ";
            cin >> fileName;

            if (remove(fileName.c_str()) == 0) {
                cout << "File deleted successfully." << endl;
            }
            else {
                cout << "Unable to delete file." << endl;
            }
        }

        else if (choice == 4) {

            cout << "Exiting program..." << endl;
        }

        else {

            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}
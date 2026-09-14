#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    cout << "How many numbers do you want to enter? ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter " << n << " numbers:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Your numbers are: ";

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (numbers[j] > numbers[j + 1]) {

                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "Sorted numbers: ";

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // Binary Search
    int target;

    cout << "Enter a number to search for: ";
    cin >> target;

    int left = 0;
    int right = n - 1;
    int foundIndex = -1;

    while (left <= right) {

        int middle = (left + right) / 2;

        if (numbers[middle] == target) {
            foundIndex = middle;
            break;
        }

        else if (numbers[middle] < target) {
            left = middle + 1;
        }

        else {
            right = middle - 1;
        }
    }

    if (foundIndex != -1) {
        cout << target << " was found at index "
             << foundIndex << "." << endl;
    }
    else {
        cout << target << " was not found." << endl;
    }

    return 0;
}

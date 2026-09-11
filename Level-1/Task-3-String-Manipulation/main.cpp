#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string text;

    cout << "Enter a string: ";
    getline(cin, text);

    // Reverse the original string
    string reversedText = "";

    for (int i = text.length() - 1; i >= 0; i--) {
        reversedText += text[i];
    }

    cout << "Reversed string: " << reversedText << endl;

    // Count vowels
    int vowelCount = 0;

    for (char c : text) {
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U') {
            vowelCount++;
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;

    // Convert to lowercase and remove spaces
    string cleanText = "";

    for (char c : text) {
        if (c != ' ') {
            cleanText += tolower(c);
        }
    }

    // Reverse the cleaned string
    string reversedCleanText = "";

    for (int i = cleanText.length() - 1; i >= 0; i--) {
        reversedCleanText += cleanText[i];
    }

    // Check palindrome
    if (cleanText == reversedCleanText) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
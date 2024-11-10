#include <iostream>
using namespace std;

int main() {
    int k;
    cout << "Enter the number of characters in the array: ";
    cin >> k;

    char arr[k];
    cout << "Enter the characters of the array: ";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    char result[k];  // new array for sorted characters
    int index = 0;

    // First, add all digits to the new array
    for (int i = 0; i < k; i++) {
        if (isdigit(arr[i])) {
            result[index] = arr[i];
            index++;
        }
    }

    // Then, add all other characters
    for (int i = 0; i < k; i++) {
        if (!isdigit(arr[i])) {
            result[index] = arr[i];
            index++;
        }
    }

    // Output the result
    cout << "Transformed array: ";
    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
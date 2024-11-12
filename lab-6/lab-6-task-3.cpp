#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin >> input;

    int length = strlen(input);  // Determine the string length
    int maxCount = 0;            // Max length
    int count = 1;        // Current length of the group

    for (int i = 1; i < length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // If the sequence is interrupted, update maxCount if the current group is longer
            if (count > maxCount) {
                maxCount = count;
            }
            count = 1;  // Reset current group length for a new group
        }
    }

    // Check the last group
    if (count > maxCount) {
        maxCount = count;
    }

    cout << maxCount << endl;

    return 0;
}

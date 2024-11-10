#include <iostream>
using namespace std;

int main() {
    int k;
    cout << "Enter the number of elements in the array: ";
    cin >> k;

    int arr[k];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    int maxCount = 0;   // maximum number of occurrences
    int mostFrequent;   // most frequently occurring number

    for (int i = 0; i < k; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    cout << "The most frequently occurring number is: " << mostFrequent << " (occurs " << maxCount << " times)" << endl;

    return 0;
}

//example
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;

    // Fill the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Count the number of positive elements
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            count++;
        }
    }

    // Create a new array for positive elements
    int positiveArr[count];
    int j = 0;

    // Fill the new array
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positiveArr[j] = arr[i];
            j++;
        }
    }

    // Output the array with positive elements only
    cout << "Array without negative elements:" << endl;
    for (int i = 0; i < count; i++) {
        cout << positiveArr[i] << " ";
    }

    return 0;
}


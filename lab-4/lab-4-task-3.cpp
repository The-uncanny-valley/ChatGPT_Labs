#include <iostream>
using namespace std;

int main() {
    int k;
    cout << "Количество элементов: ";
    cin >> k;

    int arr[k];
    cout << "Введите элементы: ";
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    int maxCount = 0;   // максимальное число повторений
    int mostFrequent;   // самое частое число

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

    cout << "Самое частое число: " << mostFrequent << " (встречается " << maxCount << " раз)" << endl;

    return 0;
}

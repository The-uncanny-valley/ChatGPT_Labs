#include <iostream>
#include <cstring>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU"); // для работы с русским языком
    char input[100];
    cout << "Введите строку: ";
    cin >> input;

    int length = strlen(input);  // длина строки
    int maxCount = 0;            // максимальное значение длины
    int count = 1;        // длина текущей последовательности

    for (int i=1; i<length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // если последовательность прервана и при это она больше значения в max, то max обновляется
            if (count > maxCount) {
                maxCount = count;
            }
            count = 1;  // сброс
        }
    }

    // проверка последнего
    if (count > maxCount) {
        maxCount = count;
    }

    cout << maxCount << endl;

    return 0;
}

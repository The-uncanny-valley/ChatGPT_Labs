#include <iostream>
using namespace std;

int countDigitsRecursive(int number) {
    if (number == 0)
        return 0;
    return 1 + countDigitsRecursive(number / 10);
}

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}


int main() {
    int number;

    cout << "Введите число: ";
    cin >> number;

    number = abs(number);

    cout << "Количество цифр (рекурсия): " << countDigitsRecursive(number) << endl;
    cout << "Количество цифр (без рекурсии): " << countDigits(number) << endl;

    return 0;
}

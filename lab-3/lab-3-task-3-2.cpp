#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// для вычисления факториала
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");

    double a, b, h, x, y, s;
    int n;

    cout << "Введите a, b, n:" << endl;
    cin >> a >> b >> n;

    h = (b - a) / 10; // шаг

    cout << setw(15) << "x" << setw(15) << "Y(x)" << setw(15) << "S(x)" << endl; // заголовок таблицы

    // Цикл для вычисления значений
    for (x = a; x <= b; x += h) {
        // Вычисление значения функции Y(x)
        y = exp(x * cos(M_PI / 4)) * cos(x * sin(M_PI / 4));

        // Вычисление разложения S(x) с использованием ряда
        s = 1;  // Начальное значение для разложения ряда
        double p = 1;  // Промежуточное значение для ряда
        for (int i = 1; i <= n; i++) {
            p *= pow(x, 2.0) / (2 * i);  // Умножаем на каждый элемент ряда
            s += p;  // Добавляем к сумме ряда
        }

        cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
    }

    return 0;
}

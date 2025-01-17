#include <iostream>
#include <cmath>
using namespace std;


int main() {
    setlocale(LC_ALL, "RU"); // для работы с русским языком
    double x, y, c;

    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    // Выбор функции f(x)
    int choice;
    double f;
    cout << "Выберите функцию f(x): 1 - sh(x), 2 - x^2, 3 - exp(x): ";
    cin >> choice;

    switch (choice) {
        case 1:
            f = sinh(x); // гиперболический синус x
            break;
        case 2:
            f = pow(x, 2.0); // степенная функция
            break;
        case 3:
            f = exp(x); // экспонента от x
            break;
        default:
            cout << "Неверный выбор функции." << endl;
            return 1;
    }

    // Проверка условий
    if ((x - y) == 0) {
        c = pow(f, 2.0) + cbrt(y) + sin(y);
        cout << "x - y = 0." << endl;
    } else if ((x - y) > 0) {
        if (x <= 0) { // Проверка для логарифма
            cout << "ln(x) не существует для x <= 0!" << endl;
            return 1;
        }
        c = pow(f - y, 2.0) + log(x);
        cout << "x - y > 0." << endl;
    } else { // x - y < 0
        c = pow(y - f, 2.0) + tan(y);
        cout << "x - y < 0." << endl;
    }

    cout << "Результат: " << c << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


int main() {
    double x, y, result, c;

    // Ввод значений x и y
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
            f = sinh(x);
            break;
        case 2:
            f = pow(x, 2.0);
            break;
        case 3:
            f = exp(x);
            break;
        default:
            cout << "Неверный выбор функции." << endl;
            return 1;
    }

    // Проверка условий
    if ((x - y) == 0) {
        c = pow(f, 2.0) + cbrt(y) + sin(y);
        cout << "Выбрано x - y = 0." << endl;
    } else if ((x - y) > 0) {
        if (x <= 0) { // Проверка для логарифма
            std::cout << "ln(x) не существует для x <= 0!" << endl;
            return 1;
        }
        c = pow(f - y, 2.0) + log(x);
        cout << "Выбрана ветвь x - y > 0." << endl;
    } else { // x - y < 0
        c = pow(y - f, 2.0) + tan(y);
        cout << "Выбрана ветвь x - y < 0." << endl;
    }

    // Вывод результата
    cout << "Результат: c = " << c << endl;

    return 0;
}

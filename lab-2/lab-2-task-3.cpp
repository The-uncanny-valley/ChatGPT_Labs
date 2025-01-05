#include <iostream>
#include <cmath>
#include <limits>

int main() {
    double x, y, result, c;

    // Ввод значений x и y
    std::cout << "Значение x: ";
    std::cin >> x;
    std::cout << "Значение y: ";
    std::cin >> y;

    // Выбор функции f(x)
    int choice;
    double f;
    std::cout << "Выберите функцию f(x): 1 - sh(x), 2 - x^2, 3 - exp(x): ";
    std::cin >> choice;

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
            std::cout << "Неверный выбор функции." << std::endl;
            return 1;
    }

    // Проверка условий
    if ((x - y) == 0) {
        c = pow(f, 2.0) + cbrt(y) + sin(y);
        std::cout << "Выбрана ветвь x - y = 0." << std::endl;
    } else if ((x - y) > 0) {
        if (x <= 0) { // Проверка для логарифма
            std::cout << "Ошибка: ln(x) не определен для x <= 0." << std::endl;
            return 1;
        }
        c = pow(f - y, 2.0) + log(x);
        std::cout << "Выбрана ветвь x - y > 0." << std::endl;
    } else { // x - y < 0
        c = pow(y - f, 2.0) + tan(y);
        std::cout << "Выбрана ветвь x - y < 0." << std::endl;
    }

    // Вывод результата
    std::cout << "Результат: c = " << c << std::endl;

    return 0;
}

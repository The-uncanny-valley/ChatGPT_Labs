#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Заданные значения
    double x, y, z, a, b, c, s;
    
    std::cout << "x:";
    std::cin >> x;
    std::cout << "y:";
    std::cin >> y;
    std::cout << "z:";
    std::cin >> z;

    // Числитель первой части
    a = 1 + pow(sin(x + y), 2.0) * pow(x, fabs(y));

    // Знаменатель первой части
    b = x - ((2 * y) / (1 + pow(x, 2.0) * pow(y, 2.0)));


    // Вторая часть выражения
    c = pow(cos(atan(1.0 / z)), 2.0);

    // Полное выражение
    s = a / fabs(b) + c;

    // Вывод результата
    std::cout << "Result s = " << s << std::endl;

    return 0;
}

    #define _USE_MATH_DEFINES // чтобы использовать математические константы из библиотеки cmath
    #include <iostream>
    #include <iomanip> // управление форматированием вывода
    #include <cmath>
    using namespace std;

    int main() {
        setlocale(LC_ALL, "RU"); // для работы с русским языком
        double a, b, h, x, y, s, p; // a, b - границы интервала, h - шаг 
        int n; // количество итераций в цикле
        cout << "Введите a, b, n" << endl;
        cin >> a >> b >> n;
        x = a;
        h = (b - a) / 10;
        do {
            p = s = 1;
            for (int i=1; i<=n; i++) {
                p *= pow(x, 2.0) / 2 * i;
                s += p;
            }
            y = exp(x * cos(M_PI_4)) * cos(x * sin(M_PI_4));
            cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
            x += h;
        }
        while (x <= b + h / 2);
        cout << endl;
        return 0;
    }

    /*Вывести на экран таблицу значений функции Y(x) и ее разложения в ряд
S(x) для x, изменяющегося от a до b с шагом h = (b – a)/10, табл. 3. */
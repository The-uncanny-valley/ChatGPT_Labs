#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU"); // для работы с русским языком
    double x, y, z, a, b, c, s; // значения
    
    cout << "x:";
    cin >> x;
    cout << "y:";
    cin >> y;
    cout << "z:";
    cin >> z;

    a = 1 + pow(sin(x + y), 2.0);

    b = fabs(x - ((2 * y) / (1 + pow(x, 2.0) * pow(y, 2.0))));

    c = pow(cos(atan(1 / z)), 2.0);

    s = a / b * pow(x, fabs(y)) + c;

    cout << "Ответ = " << s << endl;

    return 0;
}

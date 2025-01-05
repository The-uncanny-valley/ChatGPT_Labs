#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, h, x, y, s, p;
    int n, i;
    cout << "Введите a, b, n" << endl;
    cin >> a >> b >> n;
    x = a;
    h = (b - a) / 10;
    do {
        p = s = 1;
        for (i=1; i<=n; i++) {
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
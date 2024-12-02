#include <iostream>
#include <cmath>
using namespace std;

// lab 1 task 1
int main()
{
    double x, y, z, a, b, c, s;
    cout << "x:";
    cin >> x;
    cout << "y:";
    cin >> y;
    cout << "z:";
    cin >> z;
    a = 2 * cos(x - 2 / 3.0);
    b = 1 / 2.0 + sin(y) * sin(y);
    c = 1 + pow(z, 2) / (3 - pow(z, 2) / 5);
    s = a / b * c;
    cout << "Result s=" << s << endl;
}


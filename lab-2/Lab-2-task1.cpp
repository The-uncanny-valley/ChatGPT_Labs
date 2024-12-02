#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, f, a, s;
    int k;
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    cout << "f: 1 - sh(x), 2 - x^2, 3 – exp(x)"; cin >> k;
    switch (k)
    {
        case 1: f = sinh(x); break;
        case 2: f = pow(x, 2.0); break;
        case 3: f = exp(x); break;
        default: cout << "Function not chosen"; return 1;
    }
    a = x * y;
    if (a > 0) {
        s = pow(x + y, 2.0) - pow(fabs(f), 1 / 3.0);
    }
    else if (a < 0) {
        s = pow(f + y, 2.0) + sin(x);
    }
    else if (a == 0) {
        s = pow(f + y, 2.0) + pow(y, 3.0);
    }
    cout << "result = " << s << endl;
    
}
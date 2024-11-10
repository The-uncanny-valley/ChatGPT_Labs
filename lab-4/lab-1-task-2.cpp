#include <iostream>
#include <cmath>

// lab-1 task-2
int main()
{
    double x, y, z, a, b, c, s;
    
    std::cout << "x:";
    std::cin >> x;
    std::cout << "y:";
    std::cin >> y;
    std::cout << "z:";
    std::cin >> z;

    a = pow(9 + pow(x - y, 2.0), 1 / 3.0);
    b = x * x + y * y + 2;
    c = exp(fabs(x - y)) * pow(tan(z), 3.0);
    s = a / b - c;

    std::cout << "Result s=" << s << std::endl;
    return 0;
}
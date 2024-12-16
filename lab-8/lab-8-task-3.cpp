#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function Y(x)
double y(double x) {
    return cbrt(1 + x);
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the product 1 * 2 * 5 * 8 * ... * (3k - 4)
double product_sequence(int k) {
    double product = 1.0;
    for (int i = 2; i <= k; ++i) {
        product *= (3 * i - 4);
    }
    return product;
}

// Function to compute the series S(x) with a given precision eps
double s(double x, double eps, int &iterations) {
    double sum = 1.0 + x / 3.0; // Initial value of the sum (first two terms of the series)
    double term; // Current term of the series
    iterations = 0;
    int k = 2; // Initial index k
    
    do {
        double numerator = pow(-1, k - 1) * product_sequence(k) * pow(x, k);
        double denominator = pow(3, k) * factorial(k);
        term = numerator / denominator;
        sum += term;
        k++;
        iterations++;
    } while (fabs(term) > eps);
    
    return sum;
}

// Main function to print the table of Y(x) and S(x) values
void print_table(double a, double b, double h, double eps) {
    cout << setw(10) << "x" 
         << setw(15) << "Y(x)" 
         << setw(15) << "S(x)" 
         << setw(10) << "k" << endl;
    cout << string(50, '-') << endl;
    
    for (double x = a; x <= b; x += h) {
        int iterations = 0;
        double y_val = y(x);
        double s_val = s(x, eps, iterations);
        
        cout << setw(10) << fixed << setprecision(3) << x 
             << setw(15) << fixed << setprecision(5) << y_val 
             << setw(15) << fixed << setprecision(5) << s_val 
             << setw(10) << iterations << endl;
    }
}

int main() {
    double a = -0.9; // Start of the interval
    double b = 0.9;  // End of the interval
    double h = 0.1;  // Step size for x
    double eps = 0.001; // Given precision
    
    cout << "Table of Y(x) and S(x) values with precision eps = " << eps << ":\n";
    print_table(a, b, h, eps);
    
    return 0;
}

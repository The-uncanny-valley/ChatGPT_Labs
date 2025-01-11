#include <iostream>
using namespace std;

bool isSymmetric(int* row, int cols) {
    for (int i = 0; i < cols / 2; ++i) {
        if (row[i] != row[cols - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cout << "Введите количество строк (N) и столбцов (M): ";
    cin >> n >> m;

    // Динамическое выделение памяти для матрицы
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int* B = new int[n];

    for (int i = 0; i < n; ++i) {
        B[i] = isSymmetric(matrix[i], m) ? 1 : 0;
    }

    cout << "Массив B:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] B;

    return 0;
}

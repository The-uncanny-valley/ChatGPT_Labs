#include <iostream>
#include <string>
using namespace std;

struct Student {
    string fullName;      // имя
    string group;         // группа
    double averageScore;  // средний бал
    double income;        // доход на члена семьи
};

int main() {
    int n;
    cout << "Количество студентов: ";
    cin >> n;

    Student students[100]; // массив

    for (int i = 0; i < n; i++) {
        setlocale(LC_ALL, "RU"); // для работы с русским языком
        cout << "Введите информацию " << i + 1 << ":\n";
        cout << "Имя: ";
        cin.ignore(); // пропуск первого символа
        getline(cin, students[i].fullName);
        cout << "Группа: ";
        getline(cin, students[i].group);
        cout << "Средний бал: ";
        cin >> students[i].averageScore;
        cout << "Доход на члена семьи: ";
        cin >> students[i].income;
    }

    double minSalary;
    cout << "Мнимальная зарплата: ";
    cin >> minSalary;

    // Пузырьковая сортировка
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool needToSwap = false;

            // If one student's income is below the minimum salary and the other is not
            if ((students[j].income >= minSalary && students[j + 1].income < minSalary) ||
                // If the incomes are in the same category, compare by average score
                (students[j].income < minSalary == students[j + 1].income < minSalary &&
                 students[j].averageScore < students[j + 1].averageScore)) {
                needToSwap = true;
            }

            if (needToSwap) {
                // Explicitly swap all fields
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "\nПорядок предоставления мест в общежитии:\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].fullName << " (Группа: " << students[i].group
             << ", Средний бал: " << students[i].averageScore
             << ", Доход: " << students[i].income << ")\n";
    }

    return 0;
}
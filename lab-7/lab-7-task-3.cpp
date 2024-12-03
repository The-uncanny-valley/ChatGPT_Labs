#include <iostream>
#include <string>
using namespace std;

// Define a structure to store student data
struct Student {
    string fullName;      // Student's full name
    string group;         // Group
    double averageScore;  // Average score
    double income;        // Income per family member
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[100]; // Static array for students (maximum 100)

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "Enter data for student " << i + 1 << ":\n";
        cout << "Full name: ";
        cin.ignore(); // Ignore the newline character after the previous input
        getline(cin, students[i].fullName);
        cout << "Group: ";
        getline(cin, students[i].group);
        cout << "Average score: ";
        cin >> students[i].averageScore;
        cout << "Income per family member: ";
        cin >> students[i].income;
    }

    // Input the minimum salary
    double minSalary;
    cout << "Enter the minimum salary: ";
    cin >> minSalary;

    // Bubble sort without using swap
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

    // Output the sorted list of students
    cout << "\nOrder of allocation for dormitory places:\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].fullName << " (Group: " << students[i].group
             << ", Average score: " << students[i].averageScore
             << ", Income: " << students[i].income << ")\n";
    }

    return 0;
}
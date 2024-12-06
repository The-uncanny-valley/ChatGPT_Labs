#include <iostream>
#include <cstring>
using namespace std;

int main() {
    struct strc { // Определение структуры и описание полей (переменных)
        char fio[40];
        char ngr[7];
        int otc[4]; // grades
        double sb; // GPA (Grade Point Average) – средняя оценка успеваемости студента
    } mstud[100];

    int nst, i, j;
    cout << "Enter number of students: ";
    cin >> nst;

    // Input student data
    for (i = 0; i < nst; i++) {
        cout << "Enter FIO: ";
        cin >> mstud[i].fio;

        cout << "Enter group: ";
        cin >> mstud[i].ngr;

        cout << "Enter 4 grades: ";
        mstud[i].sb = 0; // Initialize GPA to 0 before calculating
        for (j = 0; j < 4; j++) {
            cin >> mstud[i].otc[j];
            mstud[i].sb += mstud[i].otc[j]; // Sum the grades
        }
        mstud[i].sb /= 4.0; // Calculate GPA after summing the grades
    }

    strc stemp; // Definition of temporary variable for swapping
    // Sort students by GPA for group "610205"
    for (i = 0; i < nst - 1; i++) {
        for (j = i + 1; j < nst; j++) {
            if (!strcmp(mstud[i].ngr, "610205") && !strcmp(mstud[j].ngr, "610205") && mstud[i].sb < mstud[j].sb) {
                stemp = mstud[i];
                mstud[i] = mstud[j];
                mstud[j] = stemp;
            }
        }
    }

    // Output the sorted list of students in group "610205"
    for (i = 0; i < nst; i++) {
        if (!strcmp(mstud[i].ngr, "610205")) {
            cout << mstud[i].fio << " " << mstud[i].ngr << " " << mstud[i].sb << endl;
        }
    }

    return 0;
}

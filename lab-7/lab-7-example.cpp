/*Программирования с использованием структур*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    struct strc { // Определение структуры и описание полей (переменных)
        char fullName[40];
        char groupID[7];
        int grades[4]; // 4 grades
        double gpa; // GPA (Grade Point Average) – средняя оценка успеваемости студента
    }
    mstud[100];

    int nst, i, j;
    cout << "Enter number of students" << endl;
    cin >> nst;
    for (i=0; i<nst; i++)
    {
        cout << "Enter full name ";
        cin >> mstud[i].fullName;

        cout << "Enter group ";
        cin >> mstud[i].groupID;

        cout << "Enter 4 grades " << endl;
        for (j=0; j<4; j++)
        {
            cin >> mstud[i].grades[j];
            mstud[i].gpa += mstud[i].grades[j] / 4.0;
        }
    }

    strc stemp; // определение переменной stemp, имеющей тип strc
    for (i=0; i<nst-1; i++) 
    {
        for (j=i+1; j<nst; j++) {
            if (mstud[i].gpa < mstud[j].gpa && !strcmp(mstud[i].groupID, "610205") && // сравнивает символы двух строк 
            !strcmp(mstud[j].groupID, "610205")) // пока не будут найдены различные символы или не будет достигнут конец строки
            {
                stemp = mstud[i];
                mstud[i] = mstud[j];
                mstud[j] = stemp;
            }
        }
    }
    for (i=0; i<nst; i++)
    {
        if (!strcmp(mstud[i].groupID, "610205")) {
            cout << mstud[i].fullName << " " << mstud[i].groupID << " " << mstud[i].gpa << endl; 
        }
    }
    return 0;
}
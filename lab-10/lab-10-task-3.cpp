#include <iostream>
#include <fstream> // для работы с файлами
#include <vector> // динамический массив
#include <iomanip>
#include <string>

using namespace std;

struct Bus {
    int number;                 // Номер рейса
    string destination;         // Пункт назначения
    string departureTime;       // Время отправления
    string arrivalTime;         // Время прибытия
};

// Добавление рейсов в файл
void addBuses(const string& filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Ошибка при открытии файла для записи.\n";
        return;
    }

    int count;
    cout << "Введите количество рейсов: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        Bus bus;
        cout << "\nРейс" << (i + 1) << ":\n";
        cout << "Номер рейса: ";
        cin >> bus.number;
        cin.ignore(); // удалить лишний символ новой строки
        cout << "Пункт назначения: ";
        getline(cin, bus.destination);
        cout << "Время отправления (HH:MM): ";
        cin >> bus.departureTime;
        cout << "Время прибытия (HH:MM): ";
        cin >> bus.arrivalTime;

        file.write(reinterpret_cast<char*>(&bus), sizeof(bus));
    }

    file.close();
    cout << "Данные успешно добавлены.\n";
}

// Функция для вывода рейсов, прибывающих раньше заданного времени
void listBuses(const string& filename, const string& specifiedTime) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Ошибка при открытии файла для чтения.\n";
        return;
    }

    Bus bus;
    int h1, m1, h2, m2;
    sscanf(specifiedTime.c_str(), "%d:%d", &h1, &m1);

    cout << "\nРейсы, прибывающие раньше " << specifiedTime << ":\n";

    while (file.read(reinterpret_cast<char*>(&bus), sizeof(bus))) {
        sscanf(bus.arrivalTime.c_str(), "%d:%d", &h2, &m2);
        if (h2 < h1 || (h2 == h1 && m2 < m1)) {
            cout << "Рейс №" << bus.number
                 << ", Пункт назначения: " << bus.destination
                 << ", Время отправления: " << bus.departureTime
                 << ", Время прибытия: " << bus.arrivalTime << '\n';
        }
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "RU"); // для работы с русским языком
    string filename = "buses.dat";
    char choice;
    string specifiedTime;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить рейсы в файл\n";
        cout << "2. Показать рейсы, прибывающие раньше заданного времени\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addBuses(filename);
                break;
            case '2':
                cout << "Введите время (HH:MM): ";
                cin >> specifiedTime;
                listBuses(filename, specifiedTime);
                break;
            case '3':
                return 0;
            default:
                cout << "Неверный выбор\n";
        }
    }
}

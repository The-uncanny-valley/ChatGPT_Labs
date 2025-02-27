/* 
препроцессор копирует содержимое подключаемого файла в текущий файл сразу после строки с #include
#include <filename> сообщает препроцессору искать файл в системных путях
(в местах хранения системных библиотек языка С++).
*/

#include <iostream> // стандартная библиотека для работы с потоками ввода и вывода в программе
#include <fstream> // стандартная библиотека C++ для работы с файлами
#include <iomanip> // стандартная библиотека C++ для форматирования ввода и вывода данных
#include <string>  // стандартная библиотека C++ для работы со строками. 
// предоставляет класс std::string, который позволяет работать с текстовыми строками (последовательностями символов)

using namespace std; // пространство имён

struct Bus { // структура 
    int number;                 // номер рейса, целочисленный тип
    string destination;         // пункт назначения, строка
    string departureTime;       // время отправления, строка
    string arrivalTime;         // время прибытия, строка
};

// добавление рейсов в файл
void addBuses(const string& filename) { // функция
    ofstream file(filename, ios::binary | ios::app); // открывает файл с именем filename для записи в бинарном формате 
    // и в режиме добавления (чтобы не перезаписать файл)
    if (!file) { // проверка, был ли файл успешно открыт
        cerr << "Ошибка при открытии файла\n"; // стандартный поток вывода ошибок
        return; // завершение работы функции
    }

    int count; // целочисленная переменная
    cout << "Введите количество рейсов: "; // для вывода текста в консоль
    cin >> count; // для ввода данных

    for (int i = 0; i < count; ++i) { // цикл для добавления каждого рейса
        Bus bus; // объявление объекта bus типа Bus, Bus является структурой
        cout << "\nРейс" << (i + 1) << ":\n";
        cout << "Номер рейса: "; // вывод текста в консоль
        cin >> bus.number; // ввод номера рейса
        cin.ignore(); // удаляет символ новой строки после ввода числа,
        // чтобы при следующем чтении строки не захватился лишний символ)
        cout << "Пункт назначения: "; // вывод текста в консоль
        getline(cin, bus.destination); /*функция, которая считывает всю строку (включая пробелы) 
        до символа новой строки (\n), и сохраняет её в переданную строковую переменную*/
        cout << "Время отправления (HH:MM): "; // вывод
        cin >> bus.departureTime; // ввод
        cout << "Время прибытия (HH:MM): "; // вывод
        cin >> bus.arrivalTime; // ввод

        file.write(reinterpret_cast<char*>(&bus), sizeof(bus)); /*записывает данные структуры в файл
        в бинарном виде.*/
    }

    file.close(); // файл закрывается
    cout << "Данные добавлены.\n"; // вывод сообщения в консоль
}

// функция для вывода рейсов, прибывающих раньше заданного времени
void listBuses(const string& filename, const string& specifiedTime) {
    ifstream file(filename, ios::binary); // открывает файл для чтения в бинарном режиме
    if (!file) { // проверка, был ли файл успешно открыт
        cerr << "Ошибка при открытии файла\n";
        return;
    }

    Bus bus; // объявление объекта bus типа Bus, Bus является структурой
    int h1, m1, h2, m2;
    sscanf(specifiedTime.c_str(), "%d:%d", &h1, &m1);

    cout << "\nРейсы, прибывающие раньше " << specifiedTime << ":\n"; // вывод

    while (file.read(reinterpret_cast<char*>(&bus), sizeof(bus))) { // цикл
        sscanf(bus.arrivalTime.c_str(), "%d:%d", &h2, &m2);
        /* разбор строки arrivalTime (в которой содержится время в формате часы:минуты) на два целых числа 
        — количество часов и минут. Функция sscanf предназначена для извлечения данных из строки
        с использованием формата. Функция позволяет читать данные из строки и преобразовывать их в указанные переменные

        строка формата "%d:%d" говорит, что нужно извлечь два целых числа, разделенных двоеточием

        &h2 и &m2 — это адреса переменных, в которые будут записаны извлеченные значения
 */
            if (h2 < h1 || (h2 == h1 && m2 < m1)) { // условие проверяет, прибыл ли рейс раньше заданного времени
            cout << "Рейс №" << bus.number // вывод
                 << ", Пункт назначения: " << bus.destination
                 << ", Время отправления: " << bus.departureTime
                 << ", Время прибытия: " << bus.arrivalTime << '\n'; // \n — это символ новой строки
        }
    }

    file.close(); // закрытие файла
}

int main() { // главная функция
    setlocale(LC_ALL, "RU"); // для работы с русским языком
    string filename = "buses.dat"; // имя файла с данными о рейсах
    char choice; // переменная для выбора действия в меню
    string specifiedTime; // строка для хранения введенного времени

    while (true) { // цикл выводит меню и позволяет выбрать действие
        cout << "\nМеню:\n"; // вывод
        cout << "1. Добавить рейсы в файл\n";
        cout << "2. Показать рейсы, прибывающие раньше заданного времени\n";
        cout << "3. Выход\n";
        cout << "Действие: ";
        cin >> choice; // ввод

        switch (choice) { /* условная конструкция, которая позволяет проверить значение переменной
        и выполнить соответствующий блок кода в зависимости от этого значения. Заменяет несколько if-else условий
        и делает код более читабельным */
            case '1':
                addBuses(filename);
                break; /* используется для немедленного выхода из конструкции switch. Оно прерывает 
                выполнение текущего переключателя */
            case '2':
                cout << "Введите время (HH:MM): "; // вывод
                cin >> specifiedTime; // ввод
                listBuses(filename, specifiedTime); // вызов функции
                break; // выход
            case '3':
                return 0;
            default:
                cout << "Неправильный ввод\n"; // вывод сообщения об ошибке
        }
    }
}

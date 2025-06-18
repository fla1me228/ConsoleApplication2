// Моя часть 
#include <iomanip>>
#include <fstream>
#include <iostream>
#include <ctime>
#define INTEGER // или DOUBLE, или CHAR
#include "function.h"
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct users {
    char login[32];
    char password[32];
};
// Метод шифрования и дешифрования Цезаря
string caesarEncrypt(const string& text, int key) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)(((c - base + key) % 26 + 26) % 26 + base);
        }
        else if (isdigit(c)) {
            result += (char)(((c - '0' + key) % 10 + 10) % 10 + '0');
        }
        else {
            result += c;
        }
    }
    return result;
}

string caesarDecrypt(const string& text, int key) {
    return caesarEncrypt(text, -key);
}

vector<users> loadUsersFromFile(const string& filename, int key) {
    vector<users> users_list;
    ifstream fileRead(filename);
    if (fileRead.is_open()) {
        string line;
        while (getline(fileRead, line)) {
            users user;
            size_t commaPos = line.find(',');
            if (commaPos != string::npos) {
                string encryptedLogin = line.substr(0, commaPos);
                string encryptedPassword = line.substr(commaPos + 1);

                string login = caesarDecrypt(encryptedLogin, key);
                string password = caesarDecrypt(encryptedPassword, key);

                if (login.length() < 32 && password.length() < 32) {
                    strcpy_s(user.login, login.c_str());
                    strcpy_s(user.password, password.c_str());
                    users_list.push_back(user);
                }
                else {
                    cerr << "Warning: Login or password too long in file. Skipping entry." << endl;
                }
            }
            else {
                cerr << "Warning: Invalid line format in file. Skipping line." << endl;
            }
        }
        fileRead.close();
    }
    else {
        cout << "File not found. Starting with a fresh user database." << endl;
    }
    return users_list;
}

void saveUsersToFile(const string& filename, const vector<users>& users_list, int key) {
    ofstream fileWrite(filename);
    if (fileWrite.is_open()) {
        for (const auto& user : users_list) {
            string encryptedLogin = caesarEncrypt(user.login, key);
            string encryptedPassword = caesarEncrypt(user.password, key);
            fileWrite << encryptedLogin << "," << encryptedPassword << endl;
        }
        fileWrite.close();
    }
    else {
        cerr << "Error opening file for writing!" << endl;
    }
}
// Рендер таблицы и меню(структура)
void RenderUsersTable(const vector<users>& users_list) {
    cout << "==== Таблица пользователей ====" << endl;
    cout << "| №  |        Логин        |      Пароль      |\n";
    cout << "-----------------------------------------------\n";
    for (size_t i = 0; i < users_list.size(); ++i) {
        cout << "| " << setw(2) << i + 1 << " | "
            << setw(18) << left << users_list[i].login << " | "
            << setw(16) << left << users_list[i].password << " |\n";
    }
    cout << "-----------------------------------------------\n";
}

int RenderMenu() {
    cout << "\n=== Главное меню ===\n";
    cout << "1. Показать пользователей\n";
    cout << "2. Удалить всех пользователей\n";
    cout << "3. Удалить пользователя по логину\n";
    cout << "4. Выйти\n";
    cout << "Выберите пункт: ";
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}
void DeleteAllUsers(vector<users>& users_list, const string& filename, int caesarKey) {
    users_list.clear();
    saveUsersToFile(filename, users_list, caesarKey);
    cout << "Все пользователи удалены.\n";
}
void DeleteUserByLogin(vector<users>& users_list, const string& filename, int caesarKey) {
    char login[32];
    cout << "Введите логин пользователя для удаления: ";
    cin.getline(login, 32);

    auto it = std::remove_if(users_list.begin(), users_list.end(),
        [&](const users& u) { return strcmp(u.login, login) == 0; });

    if (it != users_list.end()) {
        users_list.erase(it, users_list.end());
        saveUsersToFile(filename, users_list, caesarKey);
        cout << "Пользователь с логином '" << login << "' удалён.\n";
    }
    else {
        cout << "Пользователь с таким логином не найден.\n";
    }
}
// Дальше часть проекта
// Часть Тамира
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    const int size = 10;
#ifdef INTEGER
    int arr[size];
#elif defined(DOUBLE)
    double arr[size];
#elif defined(CHAR)
    char arr[size];
#endif

    FillArray(arr, size);
    cout << "Массив: ";
    ShowArray(arr, size);

    cout << "Минимум: " << MinArray(arr, size) << endl;
    cout << "Максимум: " << MaxArray(arr, size) << endl;

    SortArray(arr, size);
    cout << "Отсортированный массив: ";
    ShowArray(arr, size);

    EditArray(arr, size, 0,
#ifdef INTEGER
        999
#elif defined(DOUBLE)
        999.99
#elif defined(CHAR)
        'Z'
#endif
    );
    cout << "После редактирования: ";
    ShowArray(arr, size);

	// Метод шифрования и дешифрования Цезаря
    string filename = "users.txt";
    int caesarKey = 3;
    int index = 0;
    vector<users> users_list = loadUsersFromFile(filename, caesarKey);
    int cursor;
    cout << "Выберите 1. Зарегистрироваться 2. Войти :";
    cin >> cursor;
    cin.ignore();

    if (cursor == 1) {
        while (true) {
            users newUser;
            cout << "Введите логин (или 'end' для завершения): ";
            cin.getline(newUser.login, 32);
            if (strcmp(newUser.login, "end") == 0) {
                break;
            }
            cout << "Введите пароль: ";
            cin.getline(newUser.password, 32);

            if (strlen(newUser.login) >= 32 || strlen(newUser.password) >= 32) {
                cout << "Логин или пароль слишком длинные." << endl;
            }
            else {
                users_list.push_back(newUser);
                saveUsersToFile(filename, users_list, caesarKey);
                cout << "Регистрация успешна!" << endl;
            }
        }
    }
    else if (cursor == 2) {
        char x[32];
        char y[32];
        cout << "Введите логин: ";
        cin.getline(x, 32);
        cout << "Введите пароль: ";
        cin.getline(y, 32);

        string encryptedLogin = caesarEncrypt(x, caesarKey);
        string encryptedPassword = caesarEncrypt(y, caesarKey);

        bool found = false;
        for (const auto& user : users_list) {
            string currentEncryptedLogin = caesarEncrypt(user.login, caesarKey);
            string currentEncryptedPassword = caesarEncrypt(user.password, caesarKey);

            if (strcmp(user.login, x) == 0 && strcmp(user.password, y) == 0) {
                found = true;
                cout << "Успешный вход!" << endl;
                index++;
                break;
            }
        }
        if (!found) {
            cout << "Неверный логин или пароль." << endl;
        }
    }
    else {
        cout << "Неверный выбор." << endl;
    }
	// Рендер таблицы и меню
    while (true) {
        int choice = RenderMenu();
        if (choice == 1) {
            RenderUsersTable(users_list);
        }
        else if (choice == 2) {
            DeleteAllUsers(users_list, filename, caesarKey);
        }
        else if (choice == 3) {
            DeleteUserByLogin(users_list, filename, caesarKey);
        }
        else if (choice == 4) {
            cout << "Выход из программы.\n";
            break;
        }
        else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
	// Импорт данных из файла
    fstream file("users.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла users.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
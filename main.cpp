#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "DynamicArray.h"

using namespace std;

// Функция для работы с двусвязным списком
void workWithDoubleLinkedList() {
    cout << "=== РАБОТА С ДВУСВЯЗНЫМ СПИСКОМ ===" << endl;

    DoubleLinkedList<int> list;
    int choice, value, position;
    string input;

    do {
        cout << "\n=== ТЕКУЩИЙ СПИСОК ===" << endl;
        cout << "Вперед: ";
        list.printForward();
        cout << "Назад: ";
        list.printBackward();
        cout << "Размер: " << list.getSize() << endl;
        cout << "=========================" << endl;

        cout << "\nВЫБЕРИТЕ ОПЕРАЦИЮ:" << endl;
        cout << "1 - Добавить в начало" << endl;
        cout << "2 - Добавить в конец" << endl;
        cout << "3 - Вставить в позицию" << endl;
        cout << "4 - Удалить из начала" << endl;
        cout << "5 - Удалить из конца" << endl;
        cout << "6 - Удалить из позиции" << endl;
        cout << "7 - Получить первый элемент" << endl;
        cout << "8 - Получить последний элемент" << endl;
        cout << "9 - Получить элемент по индексу" << endl;
        cout << "10 - Очистить список" << endl;
        cout << "0 - Вернуться в меню" << endl;
        cout << "Ваш выбор: ";

        getline(cin, input);
        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Ошибка ввода! Введите число." << endl;
            continue;
        }

        try {
            switch (choice) {
            case 1:
                cout << "Введите значение: ";
                getline(cin, input);
                value = stoi(input);
                list.push_front(value);
                cout << "Элемент " << value << " добавлен в начало." << endl;
                break;

            case 2:
                cout << "Введите значение: ";
                getline(cin, input);
                value = stoi(input);
                list.push_back(value);
                cout << "Элемент " << value << " добавлен в конец." << endl;
                break;

            case 3:
                cout << "Введите позицию: ";
                getline(cin, input);
                position = stoi(input);
                cout << "Введите значение: ";
                getline(cin, input);
                value = stoi(input);
                list.insert(position, value);
                cout << "Элемент " << value << " вставлен на позицию " << position << "." << endl;
                break;

            case 4:
                list.pop_front();
                cout << "Элемент удален из начала." << endl;
                break;

            case 5:
                list.pop_back();
                cout << "Элемент удален из конца." << endl;
                break;

            case 6:
                cout << "Введите позицию: ";
                getline(cin, input);
                position = stoi(input);
                list.erase(position);
                cout << "Элемент на позиции " << position << " удален." << endl;
                break;

            case 7:
                cout << "Первый элемент: " << list.front() << endl;
                break;

            case 8:
                cout << "Последний элемент: " << list.back() << endl;
                break;

            case 9:
                cout << "Введите индекс: ";
                getline(cin, input);
                position = stoi(input);
                cout << "Элемент на позиции " << position << ": " << list.at(position) << endl;
                break;

            case 10:
                list.clear();
                cout << "Список очищен." << endl;
                break;

            case 0:
                cout << "Возврат в меню..." << endl;
                break;

            default:
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
        catch (const char* error) {
            cout << "Ошибка: " << error << endl;
        }
        catch (...) {
            cout << "Неизвестная ошибка!" << endl;
        }

    } while (choice != 0);
}

// Функция для работы с динамическим массивом
void workWithDynamicArray() {
    cout << "=== РАБОТА С ДИНАМИЧЕСКИМ МАССИВОМ ===" << endl;

    DynamicArray<int> arr;
    int choice, value, position;
    string input;

    do {
        cout << "\n=== ТЕКУЩИЙ МАССИВ ===" << endl;
        arr.print();
        cout << "Размер: " << arr.getSize() << " / Вместимость: " << arr.getCapacity() << endl;
        cout << "=========================" << endl;

        cout << "\nВЫБЕРИТЕ ОПЕРАЦИЮ:" << endl;
        cout << "1 - Добавить в конец" << endl;
        cout << "2 - Вставить в позицию" << endl;
        cout << "3 - Удалить из конца" << endl;
        cout << "4 - Удалить из позиции" << endl;
        cout << "5 - Получить первый элемент" << endl;
        cout << "6 - Получить последний элемент" << endl;
        cout << "7 - Получить элемент по индексу" << endl;
        cout << "8 - Изменить элемент по индексу" << endl;
        cout << "9 - Очистить массив" << endl;
        cout << "10 - Подробная информация" << endl;
        cout << "0 - Вернуться в меню" << endl;
        cout << "Ваш выбор: ";

        getline(cin, input);
        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Ошибка ввода! Введите число." << endl;
            continue;
        }

        try {
            switch (choice) {
            case 1:
                cout << "Введите значение: ";
                getline(cin, input);
                value = stoi(input);
                arr.push_back(value);
                cout << "Элемент " << value << " добавлен в конец." << endl;
                break;

            case 2:
                cout << "Введите позицию: ";
                getline(cin, input);
                position = stoi(input);
                cout << "Введите значение: ";
                getline(cin, input);
                value = stoi(input);
                arr.insert(position, value);
                cout << "Элемент " << value << " вставлен на позицию " << position << "." << endl;
                break;

            case 3:
                arr.pop_back();
                cout << "Элемент удален из конца." << endl;
                break;

            case 4:
                cout << "Введите позицию: ";
                getline(cin, input);
                position = stoi(input);
                arr.erase(position);
                cout << "Элемент на позиции " << position << " удален." << endl;
                break;

            case 5:
                cout << "Первый элемент: " << arr.front() << endl;
                break;

            case 6:
                cout << "Последний элемент: " << arr.back() << endl;
                break;

            case 7:
                cout << "Введите индекс: ";
                getline(cin, input);
                position = stoi(input);
                cout << "Элемент на позиции " << position << ": " << arr.at(position) << endl;
                break;

            case 8:
                cout << "Введите индекс: ";
                getline(cin, input);
                position = stoi(input);
                cout << "Введите новое значение: ";
                getline(cin, input);
                value = stoi(input);
                arr.at(position) = value;
                cout << "Элемент на позиции " << position << " изменен на " << value << "." << endl;
                break;

            case 9:
                arr.clear();
                cout << "Массив очищен." << endl;
                break;

            case 10:
                arr.printDetailed();
                break;

            case 0:
                cout << "Возврат в меню..." << endl;
                break;

            default:
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
        catch (const char* error) {
            cout << "Ошибка: " << error << endl;
        }
        catch (...) {
            cout << "Неизвестная ошибка!" << endl;
        }

    } while (choice != 0);
}

// Функция для показа главного меню
void showMainMenu() {
    cout << "=========================================" << endl;
    cout << "           ГЛАВНОЕ МЕНЮ" << endl;
    cout << "=========================================" << endl;
    cout << "1 - Работа с двусвязным списком" << endl;
    cout << "2 - Работа с динамическим массивом" << endl;
    cout << "0 - Выход" << endl;
    cout << "=========================================" << endl;
    cout << "Выберите опцию: ";
}

// Главная функция программы
int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=========================================" << endl;
    cout << "   ЛАБОРАТОРНАЯ РАБОТА №1" << endl;
    cout << "   ДВУСВЯЗНЫЙ СПИСОК И ДИНАМИЧЕСКИЙ МАССИВ" << endl;
    cout << "=========================================" << endl;

    int choice;
    string input;

    do {
        showMainMenu();
        getline(cin, input);

        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Ошибка ввода! Введите число." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            workWithDoubleLinkedList();
            break;
        case 2:
            workWithDynamicArray();
            break;
        case 0:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            getline(cin, input);
        }

    } while (choice != 0);

    cout << "Программа завершена. До свидания!" << endl;
    return 0;
}
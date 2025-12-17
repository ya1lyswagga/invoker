#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray() {
        capacity = 10;
        size = 0;
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(T value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        data[size] = value;
        size++;
    }

    void insert(int index, T value) {
        if (index < 0 || index > size) {
            throw "ОШИБКА: Неверный индекс для вставки!";
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void erase(int index) {
        if (index < 0 || index >= size) {
            throw "ОШИБКА: Неверный индекс для удаления!";
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void pop_back() {
        if (size == 0) {
            throw "ОШИБКА: Нельзя удалить из пустого массива!";
        }
        size--;
    }

    T& at(int index) {
        if (index < 0 || index >= size) {
            throw "ОШИБКА: Индекс вне границ!";
        }
        return data[index];
    }

    T& operator[](int index) {
        return at(index);
    }

    int getSize() { return size; }
    int getCapacity() { return capacity; }
    bool empty() { return size == 0; }

    void clear() {
        size = 0;
    }

    T& front() {
        if (empty()) throw "ОШИБКА: Массив пустой!";
        return data[0];
    }

    T& back() {
        if (empty()) throw "ОШИБКА: Массив пустой!";
        return data[size - 1];
    }

    void print() {
        if (empty()) {
            cout << "Массив пустой" << endl;
            return;
        }
        cout << "Массив [";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "] Размер: " << size << "/" << capacity << endl;
    }

    void printDetailed() {
        cout << "=== ИНФОРМАЦИЯ О МАССИВЕ ===" << endl;
        cout << "Размер: " << size << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Пустой: " << (empty() ? "Да" : "Нет") << endl;
        if (!empty()) {
            cout << "Первый элемент: " << front() << endl;
            cout << "Последний элемент: " << back() << endl;
        }
        cout << "Элементы: [";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
        cout << "============================" << endl;
    }
};
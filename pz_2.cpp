#include <iostream>

class DynArray {
private:
    int* data;     
    int size;       

public:
    DynArray(int n) : size(n) {
        if (n <= 0) size = 1;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    DynArray(const DynArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~DynArray() {
        delete[] data;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: выход за границы массива!\n";
            return 0;
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "Ошибка: выход за границы массива!\n";
            return;
        }
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона [-100, 100]\n";
            return;
        }
        data[index] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }

    void push_back(int value) {
        if (value < -100 || value > 100) {
            std::cout << "Ошибка: значение вне диапазона [-100, 100]\n";
            return;
        }

        int* newData = new int[size + 1];

        for (int i = 0; i < size; i++)
            newData[i] = data[i];

        newData[size] = value;

        delete[] data;
        data = newData;
        size++;
    }

    DynArray add(const DynArray& other) const {
        DynArray result(size); 

        for (int i = 0; i < size; i++) {
            int a = data[i];
            int b = (i < other.size) ? other.data[i] : 0;

            result.data[i] = a + b;
        }

        return result;
    }

    DynArray sub(const DynArray& other) const {
        DynArray result(size);

        for (int i = 0; i < size; i++) {
            int a = data[i];
            int b = (i < other.size) ? other.data[i] : 0;

            result.data[i] = a - b;
        }

        return result;
    }
};


int main() {
    DynArray arr1(5);
    DynArray arr2(3);

    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);

    arr2.set(0, 1);
    arr2.set(1, 2);
    arr2.set(2, 3);

    std::cout << "arr1: ";
    arr1.print();

    std::cout << "arr2: ";
    arr2.print();

    std::cout << "Добавляем 50 в arr1\n";
    arr1.push_back(50);
    arr1.print();

    std::cout << "Сложение arr1 + arr2:\n";
    DynArray sum = arr1.add(arr2);
    sum.print();

    std::cout << "Вычитание arr1 - arr2:\n";
    DynArray diff = arr1.sub(arr2);
    diff.print();

    return 0;
}

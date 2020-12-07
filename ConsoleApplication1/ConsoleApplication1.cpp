#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Ishape {
public:
    Ishape() {
    }
    virtual void show() {
        cout << " Абстрактная фигура " << endl;
    }
    ~Ishape() {
        cout << "Фигура удалилась" << endl;
    }
};

class MyStorage {
private:
    Ishape** objects;
    int size;
public:
    MyStorage(int size) {
        this->size = size;
        objects = new Ishape* [size];
    }

    ~MyStorage() {
        delete[] objects;
    }

    void SetObject(int index, Ishape* object) {
        objects[index] = object;
    }
    void addObject(int amount, Ishape* object) {
        size = size + amount;
        objects = new Ishape* [amount];
    }

    void delObject(int index) {
        delete[] objects;
        objects = nullptr;
    }

    Ishape& GetObject(int index) {
        return *objects[index];
    }

    int GetSize() {
        return size;
    }
};


int main() {
        setlocale(LC_ALL, "Rus");
        MyStorage storage(10);
        // добавляем в него объекты
        for (int i = 0; i < storage.GetSize(); i++)
            storage.SetObject(i, new Ishape());
        // обращаемся поочередно ко всем
        for (int i = 0; i < storage.GetSize(); i++)
            storage.GetObject(i).show();



        system("pause");
        return 0;

}
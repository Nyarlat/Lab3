#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

class Object {
public:
    Object() {
        cout << "Object()" << endl;
    }

    ~Object() {
        cout << "~Object" << endl;
    }
};

class  Subject1 : public Object {
protected: 
    int x;
public: 
    Subject1(): Object() {
        cout << "Subject1()" << endl;
        x = rand() %100;
    }
    
    ~Subject1() {
        cout << "~Subject1()" << endl;
    }
};

class  Subject2 : public Object {
protected:
    int y;
public:
    Subject2(): Object() {
        cout << "Subject2()" << endl;
        y = rand() %100;
    }

    ~Subject2() {
        cout << "~Subject2()" << endl;
    }
};

class MyStorage {
private:
    Object** objects;
    int size;
public:
    int amount;
    MyStorage(int size) {
        amount = 0;
        this->size = size;
        objects = new Object* [size];
        cout << "MyStorage()" << endl;
        for (int i = 0; i < this->size; i++) {
            objects[i] = NULL;
        }
    }

    ~MyStorage() {
        delete[] objects;
    }

    void addObject(Object* NewObject, int index) {
        if (index < size) {
            cout << "add" << endl;
            objects[index] = NewObject;
            amount++;
        }
        else 
            cout << "Error: add" << endl;
    }
    
    void delObject(int index) {
        if (objects[index] != NULL) {
            objects[index] = NULL;
            amount--;
            cout << "dell" << endl;
        }
        else
            cout << "Error: del" << endl;
    }

    Object* getSubject(int index) {
        if (index < size) {
            return objects[index];
        }
        else {
            cout << "error" << endl;
            return NULL;
        }
    }
};


int main() {
    setlocale(LC_ALL, "Rus");
    unsigned int starttime = clock();
    MyStorage storage(10000);

    for (int i = 0; i < 10000; i++) {
        int random = rand() % 2;
        Object* obj;
        if (random == 1) {
            Subject1* sub1 = new Subject1();
            obj = sub1;
            storage.addObject(obj, i);
        }
        else {
            Subject2* sub2 = new Subject2();
            obj = sub2;
            storage.addObject(obj, i);
        }

        int randActions = rand() % 3;
        if (randActions == 1) {
            if (storage.getSubject(i) != NULL) {
                storage.getSubject(i);
            }
            else {
                cout << "NULL" << endl;
            }
        }
        else if (randActions == 2) {
            storage.delObject(i);
        }
        else {
            cout << storage.amount << endl;
        }

    }
    unsigned int stop = clock();
    unsigned int rezulttime = stop - starttime;
    cout << "Заняло времени: " << rezulttime << endl;
    return 0;

}
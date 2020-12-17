#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Object {
public:
    Object() {
        cout << "Object()" << endl;
    }

    ~Object() {
        cout << "~Object" << endl;
    }

    virtual void getSubject() {
        cout << "getSubject()" << endl;
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

    void getSubject() {
        cout << "x=" << x << endl;
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

    void getSubject() {
        cout << "y=" << y << endl;
    }
};

class MyStorage {
private:
    Object** objects;
    int size;
    int amount;
public:
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
        if ((index > -1) && (index < size)) {
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
        if ((index > -1) && (index < size)) {
            return objects[index];
        }
        else {
            cout << "error" << endl;
            return NULL;
        }
    }

    void resize(int Resize) {
        cout << "resize" << endl;
        int n1;
        int n2;
        Object** reObjects = new Object *[size];
        if (Resize > size) {
            n1 = size;
            n2 = Resize;
        }
        else {
            n1 = Resize;
            n2 = size;
        }
        for (int i = 0; i < n1; i++) {
            reObjects[i] = objects[i];
        }
        for (int i = 0; i < n2; i++) {
            objects[n2] = NULL;
        }
        delete[] objects;
        objects = reObjects;
    }
};


int main() {
    setlocale(LC_ALL, "Rus");
    MyStorage storage(10);

    for (int i = 0; i < 10; i++) {
        int random = rand() % 2;
        Object* obj;
        if (random == 1) {
            Subject1* sub1 = new Subject1();
            obj = sub1;
        }
        else {
            Subject2* sub2 = new Subject2();
            obj = sub2;
        }

        storage.resize(30);
        //storage.addObject(obj, i);
        //storage.delObject(i);

        if (storage.getSubject(i) != NULL) {
            storage.getSubject(i);
        }
        else {
            cout << "NULL" << endl;
        }
    }

        system("pause");
        return 0;

}
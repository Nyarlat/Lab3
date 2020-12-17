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
    }
};

class  Subject1 : public Object {
protected: 
    int x;
public: 
    Subject1(): Object() {
        cout << "Subject1()" << endl;
        x = rand();
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
        y = rand();
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

    int GetSize() {
        return size;
    }
};


int main() {
        setlocale(LC_ALL, "Rus");
        MyStorage storage(10);
        // добавляем в него объекты
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
            if (storage.getSubject(i) != NULL) {
                storage.getSubject(i);
            }
            else {
                cout << "NULL" << endl;
            }
            storage.addObject(obj, i);
            storage.delObject(i);
            if (storage.getSubject(i) != NULL) {
                storage.getSubject(i);
            }
            else {
                cout << "NULL" << endl;
            }
        }
        //for (int i = 0; i < storage.GetSize(); i++)
            //storage.show_value(i);
        //for (int i = 0; i < storage.GetSize(); i++)
            //storage.delObject(i);

        

        system("pause");
        return 0;

}
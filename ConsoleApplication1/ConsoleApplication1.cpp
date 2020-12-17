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

    virtual void show_value() {
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

    void show_value() {
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

    void show_value() {
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

    void SetObject(int index, Object* object) {
        objects[index] = object;
    }
    /*void addObject(int amount, Object* object) {
        for (int i = 1; i < amount; ++i) {
            *objects = (Object*)realloc(*objects, sizeof(Object) * i);
            //*objects[size+i] = new Ishape*;
        }
        //size = size + amount;
    }*/
    
    void delObject(int index) {
        if (objects[index] != NULL) {
            objects[index] = NULL;
            amount--;
            cout << "dell" << endl;
        }
        else
            cout << "Error del" << endl;
    }

    Object* show_value(int index) {
        if (index > -1) {
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
            storage.delObject(i);
        }
        for (int i = 0; i < storage.GetSize(); i++)
            storage.show_value(i);
        //for (int i = 0; i < storage.GetSize(); i++)
            //storage.delObject(i);

        

        system("pause");
        return 0;

}
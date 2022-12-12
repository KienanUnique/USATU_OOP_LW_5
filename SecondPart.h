#ifndef USATU_OOP_LW_5_SECONDPART_H
#define USATU_OOP_LW_5_SECONDPART_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Base {
protected:
    int someValue1;
public:
    Base() {
        cout << "Base(int set_some_val)" << endl;
        someValue1 = 0;
    }

    Base(int newSomeValue) {
        cout << "Base(int set_some_val)" << endl;
        someValue1 = newSomeValue;
    }

    Base(const Base *obj) {
        cout << "Base(const Base *obj)" << endl;
        someValue1 = obj->someValue1;
    }

    Base(const Base &obj) {
        cout << "Base(const Base &obj)" << endl;
        someValue1 = obj.someValue1;
    }

    void virtual printValues() {
        cout << someValue1 << endl;
    }

    ~Base() {
        cout << "~Base()" << endl;
    }
};

class Desc : public Base {
private:
    int someValue2;
public:
    Desc() : Base() {
        cout << "Desc() : Base()" << endl;
        someValue2 = 0;
    }

    Desc(int newSomeValue1, int newSomeValue2) : Base(newSomeValue1) {
        cout << "Desc() : Base()" << endl;
        someValue2 = newSomeValue2;
    }

    Desc(Desc *obj) : Base(obj) {
        cout << "Desc(Desc *obj)" << endl;
        obj->someValue2 = someValue2;
    }

    Desc(Desc &obj) : Base(obj) {
        cout << "Desc(Desc &obj)" << endl;
        obj.someValue2 = someValue2;
    }

    ~Desc() {
        cout << "~Desc()" << endl;
    }
};


void test_second() {
    Desc desc_1(10, 20);
    desc_1.printValues();
    cout << "======================" << endl;
    Desc *desc_2 = new Desc(desc_1);
    desc_2->printValues();
    cout << "======================" << endl;
    Desc *desc_3 = new Desc(&desc_1);
    desc_3->printValues();
    cout << "======================" << endl;
    Desc *desc_4 = new Desc(desc_2);
    desc_4->printValues();
    cout << "======================" << endl;
    unique_ptr<Base> unique_ptr_base_1(new Base(3));
    unique_ptr_base_1->printValues();
    cout << "======================" << endl;
    unique_ptr<Base> unique_ptr_base_2;
    unique_ptr_base_2 = move(unique_ptr_base_1);
    if (unique_ptr_base_1 != nullptr) {
        unique_ptr_base_1->printValues();
    } else {
        cout << "Can not access to unique_ptr_base_1" << endl;
    }
    unique_ptr_base_2->printValues();
    cout << "======================" << endl;
    shared_ptr<Desc> shared_ptr_desc_1(new Desc(3, 2));
    shared_ptr_desc_1->printValues();
    cout << "======================" << endl;
    shared_ptr<Desc> shared_ptr_desc_2(shared_ptr_desc_1);
    shared_ptr_desc_1->printValues();
    shared_ptr_desc_2->printValues();
    cout << "======================" << endl;

    delete desc_2;
    delete desc_3;
    delete desc_4;
    delete unique_ptr_base_2.get();
    delete shared_ptr_desc_1.get();
}

#endif //USATU_OOP_LW_5_SECONDPART_H
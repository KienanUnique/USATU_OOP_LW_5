#ifndef USATU_OOP_LW_5_THIRDPART_H
#define USATU_OOP_LW_5_THIRDPART_H

#include <iostream>
#include <string>

using namespace std;

class BaseClass {
public:
    BaseClass() {
        cout << "BaseClass()" << endl;
    }

    virtual ~BaseClass() {
        cout << "~BaseClass()" << endl;
    }

    void MethodWithoutVirtual() {
        cout << "BaseClass: MethodWithoutVirtual()" << endl;
        MethodNonVirtual();
    }

    void MethodNonVirtual() {
        cout << "BaseClass: MethodNonVirtual()" << endl;
    }

    void MethodWithVirtual() {
        cout << "BaseClass: MethodWithVirtual()" << endl;
        MethodVirtual();
    }

    virtual void MethodVirtual() {
        cout << "BaseClass: MethodVirtual()" << endl;
    }
};

class ClassChild : public BaseClass {
public:
    ClassChild() {
        cout << "ClassChild()" << endl;
    }

    ~ClassChild() {
        cout << "~ClassChild()" << endl;
    }

    void MethodNonVirtual() {
        cout << "ClassChild: MethodNonVirtual()" << endl;
    }

    void MethodVirtual() {
        cout << "ClassChild: MethodVirtual()" << endl;
    }
};

void test_third() {
    cout << endl << endl << "====================== delete ======================" << endl;
    ClassChild *class_child_to_delete = new ClassChild();
    delete class_child_to_delete;

    cout << endl << "====================== constructors ======================" << endl;
    BaseClass *child_as_base = new ClassChild();
    ClassChild *child_as_child = new ClassChild();

    cout << endl << "====================== child_as_base->MethodWithVirtual() ======================" << endl;
    child_as_base->MethodWithVirtual();

    cout << endl << "====================== child_as_base->MethodWithoutVirtual() ======================" << endl;
    child_as_base->MethodWithoutVirtual();

    cout << endl << "====================== child_as_base->MethodVirtual() ======================" << endl;
    child_as_base->MethodVirtual();

    cout << endl << "====================== child_as_base->MethodNonVirtual() ======================" << endl;
    child_as_base->MethodNonVirtual();

    cout << endl << "====================== child_as_child->MethodVirtual() ======================" << endl;
    child_as_child->MethodVirtual();

    cout << endl << "====================== child_as_child->MethodNonVirtual() ======================" << endl;
    child_as_child->MethodNonVirtual();

    cout << endl << endl << "====================== delete ======================" << endl;
    delete child_as_base;
    delete child_as_child;
}

#endif //USATU_OOP_LW_5_THIRDPART_H

#ifndef USATU_OOP_LW_5_FIRSTPART_H
#define USATU_OOP_LW_5_FIRSTPART_H

#include <iostream>
#include <string>

using namespace std;

namespace NamespaceWithClassNames {
    const string NameClassWithNames = "ClassWithNames";
    const string NameClassA = "ClassA";
    const string NameClassB = "ClassB";
}

class ClassWithNames {
public:
    virtual string GetClassName() {
        return NamespaceWithClassNames::NameClassWithNames;
    }

    virtual bool IsA(const string &className) {
        return className == NamespaceWithClassNames::NameClassWithNames;
    }
};

class ClassA : public ClassWithNames {
private:
    int checkValue;
public:
    ClassA(int checkValueToSet) : checkValue(checkValueToSet) {

    }

    string GetClassName() override {
        return NamespaceWithClassNames::NameClassA;
    }

    bool IsA(const string &className) override {
        return className == NamespaceWithClassNames::NameClassA;
    }

    void PrintHelloFromA() {
        cout << "Hello from class A" << endl;
    }

    void PrintCheckValue() {
        cout << checkValue << endl;
    }
};

class ClassB : public ClassWithNames {
public:
    string GetClassName() override {
        return NamespaceWithClassNames::NameClassB;
    }

    bool IsA(const string &className) override {
        return className == NamespaceWithClassNames::NameClassB;
    }

    void PrintByeFromB() {
        cout << "Bye from class B" << endl;
    }
};

class RandomClass {

};

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

void func1_parameter(ClassWithNames obj) {
    cout << obj.GetClassName() << endl;
}

void func2_parameter(ClassWithNames *obj) {
    cout << obj->GetClassName() << endl;
}

void func3_parameter(ClassWithNames &obj) {
    cout << obj.GetClassName() << endl;
}

ClassWithNames func1_return() {
    return ClassB();
}

ClassWithNames *func2_return() {
    return new ClassB();
}

ClassWithNames &func3_return() {
    ClassWithNames *classWithNames = new ClassB();
    return *classWithNames;
}

void test_first() {
    ClassWithNames **classWithNamesMassive = new ClassWithNames *[5];
    ClassA *classA = new ClassA(10);
    ClassB *classB = new ClassB();
    RandomClass *randomClass = new RandomClass();
    classWithNamesMassive[0] = classA;
    classWithNamesMassive[1] = classB;

    cout << "======================" << endl;
    cout << classA->GetClassName() << endl;
    cout << "Is ClassA: " << classA->IsA(NamespaceWithClassNames::NameClassA) << endl;
    cout << "Is ClassB: " << classA->IsA(NamespaceWithClassNames::NameClassB) << endl;
    cout << "======================" << endl;
    cout << classB->GetClassName() << endl;
    cout << "Is ClassA: " << classB->IsA(NamespaceWithClassNames::NameClassA) << endl;
    cout << "Is ClassB: " << classB->IsA(NamespaceWithClassNames::NameClassB) << endl;
    cout << "======================" << endl;
    cout << classWithNamesMassive[0]->GetClassName() << endl;
    cout << classWithNamesMassive[1]->GetClassName() << endl;
    cout << "======================" << endl;

    ClassA *unsafe_cast_classA = (ClassA *) classWithNamesMassive[0];
    ClassB *unsafe_cast_classB = (ClassB *) classWithNamesMassive[1];
    ClassA *unsafe_cast_classA_from_RandomClass = (ClassA *) randomClass;
    unsafe_cast_classA->PrintHelloFromA();
    unsafe_cast_classA->PrintCheckValue();
    unsafe_cast_classB->PrintByeFromB();
    unsafe_cast_classA_from_RandomClass->PrintCheckValue();
    cout << "======================" << endl;
    ClassA *static_cast_classA = static_cast<ClassA *>(classWithNamesMassive[0]);
    ClassB *static_cast_classB = static_cast<ClassB *>(classWithNamesMassive[1]);
    static_cast_classA->PrintHelloFromA();
    static_cast_classB->PrintByeFromB();
    cout << "======================" << endl;
    ClassA *dynamic_cast_classA = dynamic_cast<ClassA *>(classWithNamesMassive[0]);
    ClassB *dynamic_cast_classB = dynamic_cast<ClassB *>(classWithNamesMassive[1]);
    dynamic_cast_classA->PrintHelloFromA();
    dynamic_cast_classB->PrintByeFromB();
    cout << "======================" << endl;
    ClassA *reinterpret_cast_classA = (ClassA *) (randomClass);
    reinterpret_cast_classA->PrintCheckValue();
    cout << "======================" << endl;

    ClassChild *class_child_to_delete = new ClassChild();
    delete class_child_to_delete;
    cout << "======================" << endl;
    BaseClass *child_as_base = new ClassChild();
    ClassChild *child_as_child = new ClassChild();
    cout << "======================" << endl;
    child_as_base->MethodWithVirtual();
    cout << "======================" << endl;
    child_as_base->MethodWithoutVirtual();
    cout << "======================" << endl;
    child_as_base->MethodVirtual();
    cout << "======================" << endl;
    child_as_base->MethodNonVirtual();
    cout << "======================" << endl;
    child_as_child->MethodVirtual();
    cout << "======================" << endl;
    child_as_child->MethodNonVirtual();
    cout << "======================" << endl;
    delete child_as_base;
    delete child_as_child;
    cout << "======================" << endl;

    ClassB classB1 = ClassB();
    ClassWithNames *classWithNames = new ClassB();
    cout << "======================" << endl;
    func1_parameter(classB1);
    cout << "======================" << endl;
    func2_parameter(classWithNames);
    cout << "======================" << endl;
    func3_parameter(classB1);
    cout << "======================" << endl;
    cout << func1_return().GetClassName() << endl;
    cout << "======================" << endl;
    cout << func2_return()->GetClassName() << endl;
    cout << "======================" << endl;
    cout << func3_return().GetClassName() << endl;
    cout << "======================" << endl;

    delete classA;
    delete classB;
    delete classWithNames;
    delete reinterpret_cast_classA;
    delete unsafe_cast_classA;
    delete unsafe_cast_classB;
    delete unsafe_cast_classA_from_RandomClass;
}

#endif //USATU_OOP_LW_5_FIRSTPART_H

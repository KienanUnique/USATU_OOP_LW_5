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
        return className == NamespaceWithClassNames::NameClassA || ClassWithNames::IsA(className);
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
        return className == NamespaceWithClassNames::NameClassB || ClassWithNames::IsA(className);
    }

    void PrintByeFromB() {
        cout << "Bye from class B" << endl;
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
    ClassA *classA = new ClassA(10);
    ClassB *classB = new ClassB();
    ClassWithNames **classWithNamesMassive = new ClassWithNames *[5];
    classWithNamesMassive[0] = classA;
    classWithNamesMassive[1] = classB;

    cout << endl << "====================== classA->GetClassName() ======================" << endl;
    cout << classA->GetClassName() << endl;
    cout << "Is ClassA: " << classA->IsA(NamespaceWithClassNames::NameClassA) << endl;
    cout << "Is ClassB: " << classA->IsA(NamespaceWithClassNames::NameClassB) << endl;

    cout << endl << "====================== classB->GetClassName() ======================" << endl;
    cout << classB->GetClassName() << endl;
    cout << "Is ClassA: " << classB->IsA(NamespaceWithClassNames::NameClassA) << endl;
    cout << "Is ClassB: " << classB->IsA(NamespaceWithClassNames::NameClassB) << endl;

    cout << endl << "====================== classWithNamesMassive->GetClassName() ======================" << endl;
    cout << classWithNamesMassive[0]->GetClassName() << endl;
    cout << classWithNamesMassive[1]->GetClassName() << endl;

    cout << endl << "====================== static_cast ======================" << endl;
    ClassA *static_cast_classA = static_cast<ClassA *>(classWithNamesMassive[0]);
    ClassB *static_cast_classB = static_cast<ClassB *>(classWithNamesMassive[1]);
    ClassA *static_cast_classB_as_classA = static_cast<ClassA *>(classWithNamesMassive[1]);
    static_cast_classA->PrintHelloFromA();
    static_cast_classB->PrintByeFromB();
    static_cast_classB_as_classA->PrintHelloFromA();
    cout << static_cast_classA->GetClassName() << endl;
    cout << static_cast_classB->GetClassName() << endl;
    cout << static_cast_classB_as_classA->GetClassName() << endl;

    cout << endl << "====================== dynamic_cast ======================" << endl;
    ClassA *dynamic_cast_classA = dynamic_cast<ClassA *>(classWithNamesMassive[0]);
    ClassB *dynamic_cast_classB = dynamic_cast<ClassB *>(classWithNamesMassive[1]);
    ClassA *dynamic_cast_classB_as_classA = dynamic_cast<ClassA *>(classWithNamesMassive[1]);
    dynamic_cast_classA->PrintHelloFromA();
    dynamic_cast_classB->PrintByeFromB();
    if (dynamic_cast_classB_as_classA == nullptr) {
        cout << "dynamic_cast_classB_as_classA is nullptr" << endl;
    } else {
        dynamic_cast_classB_as_classA->PrintHelloFromA();
        cout << dynamic_cast_classB_as_classA->GetClassName() << endl;
    }
    cout << dynamic_cast_classA->GetClassName() << endl;
    cout << dynamic_cast_classB->GetClassName() << endl;

    cout << endl << "====================== constructors 3 ======================" << endl;
    ClassB classB1 = ClassB();
    ClassWithNames *classWithNames = new ClassB();

    cout << endl << "====================== func1_parameter(classB1) ======================" << endl;
    func1_parameter(classB1);

    cout << endl << "====================== func2_parameter(classWithNames) ======================" << endl;
    func2_parameter(classWithNames);

    cout << endl << "====================== func3_parameter(classB1) ======================" << endl;
    func3_parameter(classB1);

    cout << endl << "====================== func1_return().GetClassName() ======================" << endl;
    cout << func1_return().GetClassName() << endl;

    cout << endl << "====================== func2_return()->GetClassName() ======================" << endl;
    cout << func2_return()->GetClassName() << endl;

    cout << endl << "====================== func3_return().GetClassName() ======================" << endl;
    cout << func3_return().GetClassName() << endl;

    delete static_cast_classA;
    delete static_cast_classB;
    delete classA;
    delete classB;
    delete classWithNames;
    delete dynamic_cast_classA;
    delete dynamic_cast_classB;
}

#endif //USATU_OOP_LW_5_FIRSTPART_H
#include <iostream>
#include <string>

using namespace std;

//TODO: add cast with IsA check
//TODO: move first block to the separate file

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

    void PrintCheckValue(){
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

int main() {
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
    ClassA *reinterpret_cast_classA = reinterpret_cast<ClassA *>(randomClass);
    reinterpret_cast_classA->PrintCheckValue();
    cout << "======================" << endl;
    int static_cast_int_2 = (int) '}';
    cout << static_cast_int_2 << endl;
    cout << "======================" << endl;
    return EXIT_SUCCESS;
}
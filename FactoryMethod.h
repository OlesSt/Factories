#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <iostream>

namespace FactoryMethod
{

class Parent
{
public:
    virtual void doStuff() = 0;
    virtual ~Parent() {}
};

class Child_1 : public Parent
{
public:
    void doStuff() override { std::cout << "\n= FACTORY METHOD : Child 1 - do stuff" << std::endl;}
};

class Child_2 : public Parent
{
public:
    void doStuff() override { std::cout << "= FACTORY METHOD : Child 2 - do stuff" << std::endl;}
};

class IFactory
{
public:
    Parent *createChild_01() {return new Child_1();}
    Parent *createChild_02() {return new Child_2();}
};

void runFactoryMethod()
{
    IFactory f;

    auto *child01 = f.createChild_01();
    auto *child02 = f.createChild_02();

    child01->doStuff();
    child02->doStuff();

    delete child01;
    delete child02;
}
}

#endif // FACTORYMETHOD_H

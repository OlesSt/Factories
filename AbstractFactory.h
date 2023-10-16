#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

namespace AbstractFactory
{

// CREATE INTERFACE FOR CHILD CLASSES
class Parent
{
public:
    virtual ~Parent() {}
    virtual void doStuff(int id) = 0;
};

// ...AND CHILD CLASSES
class Child01 : public Parent
{
public:
    void doStuff(int id) override { std::cout << "\n= ABSTRACT FACTORY : Child " << id << " - do Stuff" << std::endl; }
};

class Child02 : public Parent
{
public:
    void doStuff(int id) override { std::cout << "= ABSTRACT FACTORY : Child " << id << " - do Stuff" << std::endl; }
};

// CREATE A FACTORY INTERFACE
class ParentFactory
{
public:
    virtual ~ParentFactory() {}
    virtual Parent* create() = 0;
};


// CREATE FACTORIES FOR ALL CHILD CLASSEs
class Child01_Factory : public ParentFactory
{
public:
    Parent* create() override { return new Child01(); }
};

class Child02_Factory : public ParentFactory
{
public:
    Parent* create() override { return new Child02(); }
};

void runAbstractFactory()
{
    // CREATE FACTORIES FOR EACH OF CHILD CLASS
    auto *child01_Factory = new Child01_Factory();
    auto *child02_Factory = new Child02_Factory();

    // CREATE OBJECTS
    auto *child01 = child01_Factory->create();
    auto *child02 = child02_Factory->create();
    child01->doStuff(1);
    child02->doStuff(2);

    // USE SMART POINTERS INSTEAD OF...
    delete child01;
    delete child02;
    delete child01_Factory;
    delete child02_Factory;

}
}

#endif // ABSTRACTFACTORY_H

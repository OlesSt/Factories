#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H

#include <iostream>
#include <map>
#include <memory>

namespace SmartFactory
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
    void doStuff(int id) override { std::cout << "\n= SMART FACTORY : Child " << id << " - do Stuff" << std::endl; }
};

class Child02 : public Parent
{
public:
    void doStuff(int id) override { std::cout << "= SMART FACTORY : Child " << id << " - do Stuff" << std::endl; }
};

// CREATE A FACTORY INTERFACE
class ParentFactory
{
public:
    virtual ~ParentFactory() {}
    virtual std::unique_ptr<Parent> create() = 0;
};


// CREATE FACTORIES FOR ALL CHILD CLASSEs
class Child01_Factory : public ParentFactory
{
public:
    std::unique_ptr<Parent> create() override { return std::make_unique<Child01>(); }
};

class Child02_Factory : public ParentFactory
{
public:
    std::unique_ptr<Parent> create() override { return std::make_unique<Child02>(); }
};

// CREATE A CLASS FOR CREATING THE OBJECT
class Creator
{
public:
    Creator()
    {
        // Set connection between id and created Child Class
        objects[1] = std::make_unique<Child01_Factory>();
        objects[2] = std::make_unique<Child02_Factory>();
    }

    // Create Child by id
    std::unique_ptr<Parent> createChild(int id)
    {
        if (id < 1 && id > 2)
        {
            std::cout << "Id must be 1 or 2" << std::endl;
            return nullptr;
        }
        else
        {
        auto object = objects[id]->create();
        object->doStuff(id);
        return object;
        }
    }
private:
    // Map will read the input id and create the object by it
    std::map<int, std::unique_ptr<ParentFactory>> objects;
};

void runSmartFactory()
{
    Creator c;
    auto child_o1 = c.createChild(1);
    auto child_o2 = c.createChild(2);
}
}

#endif // SMARTFACTORY_H

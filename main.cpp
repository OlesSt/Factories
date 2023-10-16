#include <QCoreApplication>

#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "SmartFactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FactoryMethod::runFactoryMethod();
    AbstractFactory::runAbstractFactory();
    SmartFactory::runSmartFactory();

    return a.exec();
}

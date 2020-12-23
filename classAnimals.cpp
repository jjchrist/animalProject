#include "classAnimals.h"

Animals::Animals(std::string name, int age)
{
	_name = name;
	_age = age;
}

void Animals::printAnimals()
{
	std::cout << "  family: " << getFamily() << "\tname: " << getName() << "\tage: " << getAge() << " y.o \t ";
}

void Animals::print()
{
	printAnimals();
}

void Animals::editAnimal()
{
    int c = 0;
    std::cout << "\nEdit:\t1 - name\n\t2 - age\n\t3 - family\n\t0 - exit\nEnter: ";
    std::cin >> c;
    switch (c)
    {
    case 1:
    {   std::string name;
        std::cout << "\nEnter new name: ";
        std::cin.ignore();
        getline(std::cin, name);
        setName(name);}
    break;
    case 2:
        int age;
        std::cout << "\nEnter new age: ";
        std::cin >> age;
        setAge(age);
        break;
    case 3:
    {   std::string family;
        std::cout << "\nEnter new family: ";
        std::cin.ignore();
        getline(std::cin, family);
        setFamily(family);
    }
        break;
     case 0:
         return;
     default:
         "\nThe action was not chosen!\n";
    }
}

void Animals::edit()
{
    std::cout << "\nEdit\n";
}

void Animals::save(std::ofstream& F)
{
    saveAnimal(F);
}

void Animals::saveAnimal(std::ofstream& F)
{
    F << "  family: " << getFamily() << "\tname: " << getName() << "\tage: " << getAge() << " y.o \t ";
}

//void Animals::sort()
//{ }








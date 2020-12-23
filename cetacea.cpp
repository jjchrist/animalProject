#include "cetacea.h"

Cetacea::Cetacea(std::string name, int age, std::string place, double size):Animals(name, age)
{
    _cplace = place;
    _size = size;
}

const std::string Cetacea::getPlace()
{
    return _cplace;
}

const double Cetacea::getSize()
{
    return _size;
}

void Cetacea::print()
{
    printAnimals();
    std::cout << " place: " << getPlace() << "\t\tsize (in metres): " << getSize() << std::endl;
}

void Cetacea::edit()
{
    int c = 0;
    std::cout << "\nEdit:\t1 - place\n\t2 - size\n\t0 - exit\nEnter: ";
    std::cin >> c;
    switch (c)
    {
    case 1:
    {   std::string place;
    std::cout << "\nEnter new place: ";
    std::cin.ignore();
    getline(std::cin, place);
    setPlace(place);}
    break;
    case 2:
        double size;
        std::cout << "\nEnter new size: ";
        std::cin >> size;
        setSize(size);
        break;
    case 0:
        return;
    default:
        "\nThe action was not chosen!\n";
    }
}

void Cetacea::save(std::ofstream& F)
{
    saveAnimal(F);
    F << " place: " << getPlace() << "\t\tsize (in metres): " << getSize() << std::endl;
}



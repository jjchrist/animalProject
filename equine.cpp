#include "equine.h"

Equine::Equine(std::string name, int age, std::string species, std::string colour, double height): Animals(name, age)
{
    _species = species;
    _colour = colour;
    _height = height;
}

const std::string Equine::getSpecies()
{
    return _species;
}

const std::string Equine::getColour()
{
    return _colour;
}

const double Equine::getHeight()
{
    return _height;
}

void Equine::print()
{
    printAnimals();
    std::cout << " species: " << getSpecies() << "\tcolour: " << getColour() << "\t\theight (in metres): " << getHeight() << std::endl;
}

void Equine::edit()
{
    int c = 0;
    std::cout << "\nEdit:\t1 - species\n\t2 - colour\n\t3 - height\n\t0 - exit\nEnter: ";
    std::cin >> c;
    switch (c)
    {
    case 1:
    {   std::string species;
        std::cout << "\nEnter new species: ";
        std::cin.ignore();
        getline(std::cin, species);
        setSpecies(species);}
        break;
    case 2:
    {
        std::string colour;
        std::cout << "\nEnter new colour: ";
        std::cin.ignore();
        getline(std::cin, colour);
        setColour(colour);}
        break;
    case 3:
        int height;
        std::cout << "\nEnter new height: ";
        std::cin >> height;
        setHeight(height);
        break;
    case 0:
        return;
    default:
        "\nThe action was not chosen!\n";
    }
}

void Equine::save(std::ofstream& F)
{
    saveAnimal(F);
    F << " species: " << getSpecies() << "\tcolour: " << getColour() << "\t\theight (in metres): " << getHeight() << std::endl;
}

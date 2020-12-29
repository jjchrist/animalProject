#include "canines.h"

Canines::Canines(std::string name, int age, std::string food, int danger): Animals(name, age)
{
    _food = food;
    _dangerLevel = danger;
}

const std::string Canines::getFood()
{
    return _food;
}

const int Canines::getDanger()
{
    return _dangerLevel;
}

void Canines::print()
{
    printAnimals();
    std::cout << " food: " << getFood() << "\t\tlevel of danger: " << getDanger() << std::endl;
}

void Canines::edit()
{
    int c = 0;
    std::cout << "\nEdit:\t1 - food\n\t2 - danger\n\tEnter: ";
    std::cin >> c;
    switch (c)
    {
    case 1:
    {   std::string food;
        std::cout << "\nEnter new food: ";
        std::cin.ignore();
        getline(std::cin, food);
        setFood(food);}
        break;
    case 2:
        int danger;
        std::cout << "\nEnter new level of danger: ";
        std::cin >> danger;
        setDanger(danger);
        break;
     case 0:
         return;
     default:
         "\nThe action was not chosen!\n";
    }
}

void Canines::save(std::ofstream& F)
{
    saveAnimal(F);
    F  << " food: " << getFood() << "\t\tlevel of danger: " << getDanger() << std::endl;
}












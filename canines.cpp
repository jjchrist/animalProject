#include "canines.h"

Canines::Canines(std::string name, int age, std::string place, int danger): Animals(name, age)
{
    _place = place;
    _dangerLevel = danger;
}

const std::string Canines::getPlace()
{
    return _place;
}

const int Canines::getDanger()
{
    return _dangerLevel;
}

void Canines::print()
{
    printAnimals();
    std::cout << " place: " << getPlace() << "\t\tlevel of danger: " << getDanger() << std::endl;
}

void Canines::edit()
{
    int c = 0;
    std::cout << "\nEdit:\t1 - place\n\t2 - danger\n\tEnter: ";
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
    F  << " place: " << getPlace() << "\t\tlevel of danger: " << getDanger() << std::endl;
}

//void Canines::sort(const Canines& c1, const Canines& c2)
//{
//    sortByDanger(c1, c2);
//}
//
//const Canines& Canines::sortByDanger(const Canines &c1, const Canines &c2)
//{
//    if (c1._dangerLevel > c2._dangerLevel)
//        return c1;
//    else
//        return c2;
//}








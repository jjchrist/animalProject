#pragma once
#include "classAnimals.h"

class Cetacea : public Animals
{
	std::string _cplace;
	double _size;
	const std::string _family = "cetacea";
public:
	Cetacea() { _cplace = "unknown"; _size = 0; }
	Cetacea(std::string name, int age, std::string place, double size);
	const std::string getPlace();
	void setPlace(std::string place) { _cplace = place; }
	const double getSize();
	void setSize(double size) { _size = size; }
	std::string getFamily() { return _family; }
	void setFamily() { _familyAnimal = _family; }
	void print();
	void edit();
	void save(std::ofstream& F);

};

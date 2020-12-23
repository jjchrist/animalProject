#pragma once
#include "classAnimals.h"

class Equine : public Animals
{
	std::string _species;
	std::string _colour;
	double _height;
	const std::string _family = "equine";
public:
	Equine() { _species = "unknown"; _colour = "unknown"; _height = 0;}
	Equine(std::string name, int age, std::string species, std::string colour, double height);
	const std::string getSpecies();
	void setSpecies(std::string species) { _species = species; }
	const std::string getColour();
	void setColour(std::string colour) { _colour = colour; }
	const double getHeight();
	void setHeight(double height) { _height = height; }
	std::string getFamily() { return _family; }
	void setFamily() { _familyAnimal = _family; }
	void print();
	void edit();
	void save(std::ofstream& F);
};

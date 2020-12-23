#pragma once
#include "classAnimals.h"

class Canines: public Animals
{
	std::string _place;
	int _dangerLevel;
	const std::string _family = "canines";
public:
	Canines() {
		_place = "unknown"; _dangerLevel = 0;
	}
	Canines(std::string name, int age, std::string place, int danger);
	const std::string getPlace();
	void setPlace(std::string place) { _place = place; }
	const int getDanger();
	void setDanger(int danger) { _dangerLevel = danger; }
	std::string getFamily() { return _family; }
	void setFamily() { _familyAnimal = _family; }
	void print();
	void edit();
	void save(std::ofstream& F);
	//virtual void sort(const Canines& c1, const Canines& c2);
	//const Canines& sortByDanger(const Canines& c1, const Canines& c2);
};
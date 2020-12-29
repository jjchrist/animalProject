#pragma once
#include "classAnimals.h"

class Canines: public Animals
{
	std::string _food;
	int _dangerLevel;
	const std::string _family = "canines";
public:
	Canines() {
		_food = "unknown"; _dangerLevel = 0;
	}
	Canines(std::string name, int age, std::string place, int danger);
	const std::string getFood();
	void setFood(std::string food) { _food = food; }
	const int getDanger();
	void setDanger(int danger) { _dangerLevel = danger; }
	std::string getFamily() { return _family; }
	void setFamily() { _familyAnimal = _family; }
	void print();
	void edit();
	void save(std::ofstream& F);
};

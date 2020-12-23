#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Animals
{
	std::string _name;
	int _age;
protected:
	std::string _familyAnimal = "unknown"; // семейство

public:
	Animals() { _name = "unknown"; _age = 0; }
	Animals(std::string name, int age);
	const std::string getName() { return _name; }
	void setName(std::string name) { _name = name; }
	void setAge(int age) { _age = age; }
	const int getAge() { return _age; }
	virtual std::string getFamily() { return _familyAnimal; }
	void setFamily(std::string family) { _familyAnimal = family; }
	virtual void print();
	void printAnimals();
	void editAnimal();
	virtual void edit();
	virtual void save(std::ofstream& F);
	void saveAnimal(std::ofstream &F);
	//virtual void sort();
	
};

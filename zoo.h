#pragma once
#include "classAnimals.h"
#include "canines.h"
#include "equine.h"
#include "cetacea.h"
#include "vector"
#include <iterator>
#include <algorithm>

class Zoo
{
public:
	
	std::vector <Animals*> zoo;
	Zoo() {};
	void addAnimal();
	void addCanines();
	void addEquine();
	void addCetacea();
	void del();
	void deleteZoo(); // удаление всех животных
	void deleteAnimal(std::string family); // удаление по типу
	void delAnimal(); // удаление по ID
	void editByFamily(std::string family, int id);
	void edit();
	void print();
	void printZoo();
	void printAnimals(std::string family);
	void menu();
	void load();
	void save();
	void sort(std::vector <Animals*> &arr, int ch);
	void sortBy();
};


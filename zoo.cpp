#include "zoo.h"

std::string unknownString()
{
	std::string line;
	std::cin.ignore();
	getline(std::cin, line);
	if (line == "-")
		return "-";
	else 
		return line;
}

std::string enterName()
{
	std::cout << "Enter the name: ";
	std::string name = unknownString();
	return name;
}
int enterAge()
{
	int age;
	std::cout << "Enter the age: ";
	std::cin >> age;
	return age;
}

void Zoo::addCanines()
{
	std::string name = enterName();
	int age = enterAge();
	std::cout << "Enter the habitat: ";
	std::string place = unknownString();
	std::cout << "Enter the level of danger (1-10): ";
	int dangerLevel;
	std::cin >> dangerLevel;
	Canines* can = new Canines(name, age, place, dangerLevel);
	zoo.push_back(can);
}
void Zoo::addEquine()
{
	std::string name = enterName();
	int age = enterAge();
	double height;
	std::cout << "Enter the species: ";
	std::string species = unknownString();
	std::cout << "Enter the height (in metres): ";
	std::cin >> height;
	std::cout << "Enter the colour: ";
	std::string colour = unknownString();

	Equine* eq = new Equine(name, age, species, colour, height);
	zoo.push_back(eq);
}
void Zoo::addCetacea()
{
	std::string name = enterName();
	int age = enterAge();
	double size = 0;
	std::cout << "Enter the habitat: ";
	std::string cetaplace = unknownString();
	std::cout << "Enter the size (in metres): ";
	std::cin >> size;
	Cetacea* ceta = new Cetacea(name, age, cetaplace, size);
	
	zoo.push_back(ceta);
}
void Zoo::addAnimal()
{
	int ch;
	while (true)
	{
		std::cout << "Add: \n\t1 - to Canines\n\t2 - to Equines\n\t3 - to Cetacea\n\t4 - add animal without family\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			addCanines();
			std::cout << "\nData was added\n";
			break;
		case 2:
			addEquine();
			std::cout << "\nData was added\n";
			break;
		case 3:
			addCetacea();
			std::cout << "\nData was added\n";
			break;
		case 4:
		{
			std::string name = enterName();
			int age = enterAge();
			Animals* animal = new Animals(name, age);
			zoo.push_back(animal);
		}
		break;
		case 0:
			return;
		default:
			std::cout << "\nThe action was not chosen!\n";
		}
	}
}

void Zoo::deleteZoo()
{
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end(); ++animal)
		delete *animal;
	zoo.clear();
	std::cout << "\nData was deleted\n\n";
}
void Zoo::deleteAnimal(std::string family)
{
	for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal)->getFamily() == family)
		{
			delete *animal;
			animal = zoo.erase(animal);
		}
		else ++animal;
	}
	std::cout << "\nData was deleted\n\n";
}

void Zoo::delAnimal()
{
	int id;
	std::cout << "Enter the ID of the animal you want to delete: ";
	std::cin >> id;
	/*for (std::vector<Animals*>::iterator animal = zoo.begin(); animal != zoo.end();)
	{
		if ((*animal) == zoo[id-1])
		{
			delete *animal;
			animal = zoo.erase(animal);
			break;
		}
		else ++animal;
	}*/
	delete zoo[id-1];
	zoo.erase(zoo.begin() + id-1);
	std::cout << "\nData was deleted\n\n";
}
void Zoo::del()
{
	int ch;
	int i = 0;
	while (true) {
		std::cout << "Choose:\n\t1 - delete all animals\n\t2 - delete canines\n\t3 - delete equines";
		std::cout << "\n\t4 - delete cetaceas\n\t5 - delete by ID\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		if (zoo.empty())
		{
			std::cout << "\nNo animals in list\n" << std::endl;
			return;
		}
		else
			switch (ch)
			{
			case 1:
				deleteZoo();
				break;
			case 2:
				deleteAnimal("canines");
				break;
			case 3:
				deleteAnimal("equine");
				break;
			case 4:
				deleteAnimal("cetacea");
				break;
			case 5:
				delAnimal();
				break;
			case 0:
				return;
			default:
				std::cout << "\nThe action was not chosen!\n";
			}
	}
}

void Zoo::editByFamily(std::string family, int id)
{
	if (zoo[id - 1]->getFamily() == family)
		zoo[id - 1]->edit();
}
void Zoo::edit()
{
	if (zoo.empty())
	{
		std::cout << "\nNo animals in list\n" << std::endl;
		return;
	}
	else {
		int id;
		std::cout << "Enter the ID of the animal you want to edit: ";
		std::cin >> id;
		if (id == -1)
		{
			std::cout << "Error! " << std::endl;
			return;
		}
		int ch;
		std::cout << "\n\t1 - main info\n\t2 - edit in Canines\n\t3 - edit in Equine\n\t4 - edit in Cetacea\n\t0 - exit\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1: 
			zoo[id - 1]->editAnimal();
		break;
		case 2:
			editByFamily("canines", id);
			break;
		case 3:
			editByFamily("equine", id);
			break;
		case 4:
			editByFamily("cetacea", id);
			break;
		case 0:
			return;
		default:
			"\nThe action was not chosen!\n";
		}
	}
	std::cout << "\nData was edited\n" << std::endl;
}

void Zoo::printAnimals(std::string family)
{
	int id = 1;
	for (const auto& animal : zoo)
	{
		if (animal->getFamily() == family)
		{
			std::cout << id;
			animal->print();
			id++;
		}
	}
}
void Zoo::printZoo()
{
	int id = 1;
	for (const auto& animal : zoo)
	{
		std::cout << id;
		animal->print();
		id++;
	}
}
void Zoo::print()
{
	int ch;
	int i = 0;
	while (true) {
		std::cout << "\nChoose:\n\t1 - print all animals\n\t2 - print canines\n\t3 - print equines\n\t4 - print cetaceas\n\t0 - exit\n\nEnter: ";
		std::cin >> ch;
		if (zoo.empty())
		{
			std::cout << "\nNo animals in list\n" << std::endl;
			return;
		}
		else
			switch (ch)
			{
			case 1:
				printZoo();
				break;
			case 2:
				printAnimals("canines");
				break;
			case 3:
				printAnimals("equine");
				break;
			case 4:
				printAnimals("cetacea");
				break;
			case 0:
				return;
			default:
				std::cout << "\nThe action was not chosen!\n";
			}
	}
}

void Zoo::load()
{
	std::ifstream file("fileZoo.txt");
	if (file.is_open())
	{
		std::cout << "\nThe file is open!" << std::endl;

		int age;
		std::string line, name, family;
		while (file >> line)
		{
			std::getline(file, line, ':');
			file >> family;
			std::getline(file, line, ':');
			file >> name;
			std::getline(file, line, ':');
			file >> age;
			Animals* an = new Animals(name, age);	
			if (family == "canines")
			{
				std::string place;
				int danger;
				std::getline(file, line, ':');
				file >> place;
				std::getline(file, line, ':');
				file >> danger;
				Canines* can = new Canines(name, age, place, danger);
				zoo.push_back(can);
			}
			if (family == "equine")
			{
				std::string species, colour;
				double height;
				std::getline(file, line, ':');
				file >> species;
				std::getline(file, line, ':');
				file >> colour;
				std::getline(file, line, ':');
				file >> height;
				Equine* eq = new Equine(name, age, species,colour, height);
				zoo.push_back(eq);
			}
			if (family == "cetacea")
			{
				std::string place;
				double size;
				std::getline(file, line, ':');
				file >> place;
				std::getline(file, line, ':');
				file >> size;
				Cetacea* ceta = new Cetacea(name, age, place, size);
				zoo.push_back(ceta);
			}
		}
		file.close();
		std::cout << "\nData was successfully loaded from file!\n" << std::endl;
	}
	else
	{
		std::cout << "\nThe file isn't open!\n" << std::endl;
		return;
	}
}

void Zoo::save()
{
	std::ofstream file ("fileZoo.txt");
	if (file.is_open())
	{
		std::cout << "\nThe file is open!" << std::endl;
		int id = 1;
		for (const auto& animal : zoo)
		{
			file << id;
			animal->save(file);
			id++;
		}
		std::cout << "\nData was successfully saved to file!\n" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "\nThe file isn't open!\n" << std::endl;
		return;
	}
}

//void Zoo::sortByName()
//{
//	std::sort(zoo.begin(), zoo.end());
//	std::cout << "\n\nSorted\n\n";
//}

//void Zoo::sortByDanger()
//{
//	for (auto i = 0; i < zoo.size(); i++)
//	{
//		if (zoo[i]->getFamily() == "canines")
//		{
//			zoo[i]->sort();
//		}
//		else i++;
//	}
//}

void Zoo::menu()
{
	int ch;
	while (true) {
	std::cout << "Choose the function:\n\t1 - print\n\t2 - add animal\n\t3 - delete\n\t4 - edit\n\t";
	std::cout << "5 - load file\n\t6 - save to file\n\t7 - sort by name\n\t8 - sort by danger\n\t0 - end program\n\nEnter: ";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
			print();
			break;
		case 2:
			addAnimal();
			break;
		case 3:
			del();
			break;
		case 4:
			edit();
			break;
		case 5:
			load();
			break;
		case 6:
			save();
			break;
		/*case 7:
			sortByName();
			break;
		case 8:
			sortByDanger();
			break;*/
		case 0:
			return;
		default:
			"\nThe action was not chosen!\n";
		}
	}
}




#include<iostream>
#include<vector>

using namespace std;

class Animal{
private:
	string name,species;
	int age,weight,hunger;
public:
	Animal(string species = "없음",string name = "없음");
	int get_age()const{return age;}
	int get_weight()const{return weight;}
	string get_name()const{return name;}
	string get_species()const{return species;}
	void set_age(int age){this->age = age;}
	void set_weight(int weight){this->weight = weight;}
	void set_name(string name){this->name = name;}
	void set_species(string species){this->species = species;}
	void feed(int food){this->hunger += food;}
};

Animal::Animal(string species,string name)
{
	age = 0;
	hunger = 100;
	weight = 10;
	this->name = name;
	this->species = species;
}

int main()
{
	Animal * dog = new Animal[3];
	cout << dog[0].get_name() << endl;

	return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class pet
{
	string name;
public:
	pet(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	virtual void speak()
	{
		cout << "pet " << name << " speaks" << endl;
	}

};

class cat :public pet
{
public:
	cat(string name) :pet(name) {}	
	void speak() override
	{
		cout << "cat " << getName() << " speaks meow\n";
	}
};

class dog :public pet
{
public:
	dog(string name) :pet(name) {}
	void speak() override	
	{
		cout << "dog " << getName() << " speaks woof\n";
	}
};

class parrot :public pet
{
public:
	parrot() :pet("Kesha") {}
	void speak() override
	{
		cout << "parrot " << getName() << " speaks Hello\n";
	}
};

void main()
{
	vector<pet*> pets;
	
	pets.push_back(new cat("Vasya"));
	pets.push_back(new dog("Pushok"));
	pets.push_back(new parrot);
	pets.push_back(new cat("Barsik"));

	for (pet*p : pets)
	{
		p->speak();
	}

	system("pause");
}
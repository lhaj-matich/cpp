#include <iostream>

using namespace std;

struct Person 
{
	char name[50];
	int age;
};

Person getData(Person);
void displayData(Person);

int main()
{
	Person data;

	data = getData(data);
	displayData(data);
	return (0);
}

void	displayData(Person p)
{
	cout << "Displaying informations: " << endl;
	cout << "Name: " << p.name << endl;
	cout << "Age: " << p.age << endl;
}

Person getData(Person p)
{
	cout << "Your name: ";
	cin.get(p.name, 50, '\n');
	cout << "Your age: ";
	cin >> p.age;
	return (p);
}

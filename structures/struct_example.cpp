#include <iostream>

using namespace std;

struct Person 
{
	char name[50];
	int age;
};

int main()
{
	Person p1;

	cout << "Enter full name: ";
	cin.get(p1.name, 100, '\n');
	cout << "Enter age: ";
	cin >> p1.age;

	cout << "Display informations: " << endl;
	cout << "Name: " << p1.name << endl;
	cout << "Age: " << p1.age << endl;

	return (0);
}

#include <iostream>

using namespace std;

struct Person 
{
	char name[50];
};

int main()
{
	Person person, *personPtr;
	personPtr = &person;
	
	cout << "Your name: ";
	cin.get(personPtr->name, 50, '\n');

	cout << "Displaying informations: " << endl;
	cout << personPtr->name << endl;

	return (0);
}

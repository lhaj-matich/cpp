#include <iostream>

using namespace std;

class Car 
{
	public:
		string brand;

	Car(string name)
	{
		brand = name;
	}
};

void	displayBrand(Car v1, Car v2)
{
	cout << "First brand: " << v1.brand << endl;
	cout << "Second brand: " << v2.brand << endl;
}

int main(void)
{
	Car ford("Fiesta"), opel("Hugo");
	displayBrand(ford, opel);
	return (0);
}

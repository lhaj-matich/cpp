#include <iostream>

using namespace std;

class Room 
{
	public:
		double length;
		double height;
		double breadth;

	double calculateArea()
	{
		return (length * breadth);
	}

	double calculateVolume()
	{
		return (length * breadth * height);
	}
};

int main()
{
	Room room1;

	room1.length = 40;
	room1.height = 49;
	room1.breadth = 15;

	cout << "The room area: " << room1.calculateArea() << endl;
	cout << "The room volume: " << room1.calculateVolume() << endl;
	return (0);
}

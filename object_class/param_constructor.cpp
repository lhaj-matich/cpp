#include <iostream>

using namespace std;

class Wall 
{
	private:
		double length;
		double height;

	public:
		Wall(double len, double hgt)
		{
			length = len;
			height = hgt;
		}

		double calculateArea()
		{
			return length * height;
		}
};

int main()
{
	Wall wall1(10.5, 8.6);
	Wall wall2(50.3, 59.2);

	cout << "Area of wall 1: " << wall1.calculateArea() << endl;
	cout << "Area of wall 2: " << wall2.calculateArea() << endl;
	return (0);
}

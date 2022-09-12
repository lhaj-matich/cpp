#include <iostream>

using namespace std;


class Wall 
{
	public:
		double width;
		double height;

		Wall(double height, double width)
		{
			width = width;
		    height = height;	
		}

		Wall(Wall &obj)
		{
			height = obj.height;
			width = obj.width;
		}

		double calculateArea()
		{
			return (width * height);
		}
};

int main()
{
	Wall wall1(10.3, 34.4);
	Wall wall2 = wall1;

	cout << "Wall2 height: " << wall2.height << endl;
	cout << "Wall2 width: " << wall2.width << endl;
	return (0);
}

#include <iostream>

using namespace std;

int absolute(float var)
{
		if (var < 0)
			var *= -1;
		return (var);
}

int absolute(int var)
{
	if (var < 0)
		var *= -1;
	return (var);
}

void	display(int a)
{
	cout << "The value is: " << a << endl;
}

void	display(int a, int b)
{
	cout << "The value of a: " << a << "The value of b: " << b << endl;
}

int main()
{
	cout << "The absolute value: " << absolute(4.4f) << endl;
	cout << "The absolute value: " << absolute(6) << endl;
	display(5);
	display(6, 3);
	return (0);
}

#include <iostream>

using namespace std;

// Demo that the static variable lives until the end of the program.

int	get_value()
{
	static int a;

	a += 1;
	return (a);
}

int main()
{
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	cout << "The value of:" << get_value() << endl;
	return (0);
}

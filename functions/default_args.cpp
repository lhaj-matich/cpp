#include <iostream>

using namespace std;

void	display(char = '*', int = 3);

int main()
{
	display();
	display('f', 5);
	return (0);
}

void	display(char c, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << c << endl;
	}
}

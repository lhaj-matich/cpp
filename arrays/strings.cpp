#include <iostream>

using namespace std;

void	display(char *);
void	display(string);

int main()
{
	string s1;
	char s2[100];

	cout << "Enter a string: ";
	getline(cin, s1);

	cout << "Enter another string: ";
	cin.get(s2, 100, '\n');

	display(s1);
	display(s2);
	return (0);
}

void	display(char *str)
{
	cout << "The string is: " << str << endl;
}

void	display(string s)
{
	cout << "The second string is: " << s << endl;
}

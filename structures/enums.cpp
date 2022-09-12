#include <iostream>

using namespace std;

enum week { Sunday, Monday, Tuesday, Wednesday, Thrusday, Friday, Saturaday };

int main()
{
	week today;

	today = Wednesday;
	cout << "Day: " << today + 1 << endl;
	return (0);
}

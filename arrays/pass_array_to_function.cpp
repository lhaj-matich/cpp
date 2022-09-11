#include <iostream>

using namespace std;

void display(int m[5])
{
	cout << "Displaying ages: " << endl;

	for (int i = 0; i < 5; ++i)
	{
		cout << "Student " << i + 1 << ": " << m[i] << endl;
	}
}

int main()
{
	int marks[5] = {10, 13, 12, 11, 20};

	display(marks);
	return (0);
}

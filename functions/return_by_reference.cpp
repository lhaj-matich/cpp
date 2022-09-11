#include <iostream>

using namespace std;

// This is just global variable
int num;

// The function will return the reference to the variable num
int &test()
{
	return num;
}

int main()
{
	// Here we can assign the value 5 to the refrence return by the function test.
	test() = 5;
	cout << "The value of num: " << num << endl;
	return (0);
}

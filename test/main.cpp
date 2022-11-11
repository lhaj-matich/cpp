#include <iostream>

int main(void)
{
	int i = 3;
	int j = 4;
	double k = static_cast<double>(i) / j;
	std::cout << k << std::endl;
	return (0);
}

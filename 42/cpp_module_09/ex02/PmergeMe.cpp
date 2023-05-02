#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe()
{
	std::cout << "\e[0;33mDefault Constructor called of PmergeMe\e[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of PmergeMe\e[0m" << std::endl;
}


// Destructor
PmergeMe::~PmergeMe()
{
	std::cout << "\e[0;31mDestructor called of PmergeMe\e[0m" << std::endl;
}

bool	PmergeMe::checkNumber(char *str)
{
	size_t i;

	i = 0;

	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	PmergeMe::checkInput(char **input, int size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (std::atoi(input[i]) < 0)
			throw PmergeMeError("The program cannot have negative numbers.");
		else if (!checkNumber(input[i]))
			throw PmergeMeError("Invalid numbers set.");
		i++;
	}
}

void	PmergeMe::insertNumbers(char **argv, int argc)
{
	size_t i;
	clock_t start;

	i = 0;
	start = clock();
	while (i < argc)
		_vecnumbers.push_back(std::atoi(argv[i++]));
	_vec_parse_time = ((double) (clock() - start)) / CLOCKS_PER_SEC * 1000000;

	i = 0;
	start = clock();
	while (i < argc)
		_deqnumbers.push_back(std::atoi(argv[i++]));
	_dec_parse_time = ((double) (clock() - start)) / CLOCKS_PER_SEC * 1000000;
}


void	PmergeMe::printUnsorted(char **argv, int argc)
{
	size_t i;

	i = 0;

	std::cout << "Before: ";
	while (i < argc)
		std::cout << argv[i++] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printSorted()
{
	size_t i;

	i = 0;

	std::cout << "After: ";
	while (i < _vecnumbers.size())
		std::cout << _vecnumbers[i] << " ";
	while (i < _deqnumbers.size())
		std::cout << _deqnumbers[i] << " ";
	std::cout << std::endl;
}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}


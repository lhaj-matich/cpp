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

	i = 0;
	_vec_parse_start_time = clock();
	while (i < argc)
		_vecnumbers.push_back(std::atoi(argv[i++]));
	_vec_parse_end_time = clock();
	i = 0;
	_dec_parse_start_time = clock();
	while (i < argc)
		_deqnumbers.push_back(std::atoi(argv[i++]));
	_dec_parse_end_time = clock();
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

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}


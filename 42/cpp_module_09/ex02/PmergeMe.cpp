#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &copy){ (void) copy; }

// Destructor
PmergeMe::~PmergeMe() { }

void	PmergeMe::SortNumbers(char **input, int size)
{
	checkInput(input, size);
	insertNumbers(input, size);
	mergeInsertSortDeq();
	mergeInsertSortVec();
	printUnsorted(input, size);
	printSorted();
	printVectorTime(size - 1);
	printDequeTime(size - 1);
}

void	PmergeMe::printVectorTime(int num)
{
	std::cout << "Time to process a range of " << num << " elements with std::vector : " <<  \
	_vec_parse_time + _vec_sort_time << " us" << std::endl;
}

void	PmergeMe::printDequeTime(int num)
{
	std::cout << "Time to process a range of " << num << " elements with std::deque : " <<  \
	_dec_parse_time + _dec_sort_time << " us" << std::endl;
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

void	PmergeMe::checkInput(char **input, size_t size)
{
	size_t i;

	i = 1;
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
	size_t args_number;
	clock_t start;

	i = 1;
	args_number = argc;
	start = clock();
	while (i < args_number)
		_vecnumbers.push_back(std::atoi(argv[i++]));
	_vec_parse_time = (double(clock() - start) / CLOCKS_PER_SEC) * 1000000;

	i = 1;
	start = clock();
	while (i < args_number)
		_deqnumbers.push_back(std::atoi(argv[i++]));
	_dec_parse_time = (double(clock() - start) / CLOCKS_PER_SEC) * 1000000;
}

// Sort Vector

std::vector<int> PmergeMe::insertionSortVector(std::vector<int> input)
{
    for (size_t i = 1; i < input.size(); i++)
    {
        int key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
    return (input);
}

std::vector<int> PmergeMe::mergeVectors(std::vector<int> leftVector, std::vector<int> rightVector)
{
	std::vector<int>::iterator i;
	std::vector<int>::iterator j;
	std::vector<int> result;

	i = leftVector.begin();
	j = rightVector.begin();
	while (i != leftVector.end() && j != rightVector.end())
    {
        if (*i <= *j)
            result.push_back(*i++);
        else
            result.push_back(*j++);
    }
    while (i != leftVector.end())
        result.push_back(*i++);
    while (j != rightVector.end())
        result.push_back(*j++);
    return (result);
}

std::vector<int> PmergeMe::mergeSortVec(std::vector<int> input)
{
	std::vector<int>::iterator middle;

	if (input.size() <= 32)
		return insertionSortVector(input);

	middle = input.begin() + input.size() / 2;

	std::vector<int> leftVector = mergeSortVec(std::vector<int>(input.begin(), middle));
	std::vector<int> rightVector = mergeSortVec(std::vector<int>(middle, input.end()));
	return mergeVectors(leftVector, rightVector);
}

void	PmergeMe::mergeInsertSortVec()
{
	clock_t start;

	start = clock();
	_vecnumbers = mergeSortVec(_vecnumbers);
	_vec_sort_time = (double(clock() - start) / CLOCKS_PER_SEC) * 1000000;
}

// Sort Deque

std::deque<int> PmergeMe::insertionSortDeque(std::deque<int> input)
{
    for (size_t i = 1; i < input.size(); i++)
    {
        int key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
    return (input);
}

std::deque<int> PmergeMe::mergeDeques(std::deque<int> leftDeque, std::deque<int> rightDeque)
{
	std::deque<int>::iterator i;
	std::deque<int>::iterator j;
	std::deque<int> result;

	i = leftDeque.begin();
	j = rightDeque.begin();
	while (i != leftDeque.end() && j != rightDeque.end())
    {
        if (*i <= *j)
            result.push_back(*i++);
        else
            result.push_back(*j++);
    }
    while (i != leftDeque.end())
        result.push_back(*i++);
    while (j != rightDeque.end())
        result.push_back(*j++);
    return (result);
}

std::deque<int> PmergeMe::mergeSortDeq(std::deque<int> input)
{
	std::deque<int>::iterator middle;

	if (input.size() <= 32)
		return insertionSortDeque(input);
	
	middle = input.begin() + input.size() / 2;

	std::deque<int> leftVector = mergeSortDeq(std::deque<int>(input.begin(), middle));
	std::deque<int> rightVector = mergeSortDeq(std::deque<int>(middle, input.end()));
	return mergeDeques(leftVector, rightVector);
}

void	PmergeMe::mergeInsertSortDeq()
{
	clock_t start;

	start = clock();
	_deqnumbers = mergeSortDeq(_deqnumbers);
	_dec_sort_time = (double(clock() - start) / CLOCKS_PER_SEC) * 1000000;
}

void	PmergeMe::printUnsorted(char **argv, int argc)
{
	size_t i;

	i = 1;

	std::cout << "Before: ";
	while (i < (size_t)argc)
		std::cout << argv[i++] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printSorted()
{
	size_t i;

	i = 0;

	std::cout << "After: ";
	// while (i < _vecnumbers.size())
	// 	std::cout << _vecnumbers[i++] << " ";
	while (i < _deqnumbers.size())
		std::cout << _deqnumbers[i++] << " ";
	std::cout << std::endl;
}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}


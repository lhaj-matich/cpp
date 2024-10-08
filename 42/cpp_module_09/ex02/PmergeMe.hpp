#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <vector>
# include <deque>
# include <ctime>

class PmergeMe
{
	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		
		// Destructor
		~PmergeMe();
		
		// Operators
		PmergeMe & operator=(const PmergeMe &assign);

		void	SortNumbers(char **, int);
		
	private:
		std::deque<int>		_deqnumbers;
		std::vector<int>	_vecnumbers;
		// Sort time variables
		double				_dec_sort_time;
		double				_vec_sort_time;
		// Parse time variables
		double				_dec_parse_time;
		double				_vec_parse_time;

		bool	checkNumber(char *);
		void	checkInput(char **, size_t);
		void	insertNumbers(char **, int);
		void	printUnsorted(char **, int);
		void	printSorted();
		void	printVectorTime(int);
		void	printDequeTime(int);

		// Sort
		void	mergeInsertSortDeq();
		void	mergeInsertSortVec();

		std::vector<int> mergeSortVec(std::vector<int>);
		std::deque<int> mergeSortDeq(std::deque<int>);

		std::deque<int>	mergeDeques(std::deque<int>, std::deque<int>);
		std::vector<int>	mergeVectors(std::vector<int>, std::vector<int>);

		std::deque<int> insertionSortDeque(std::deque<int> input);
		std::vector<int> insertionSortVector(std::vector<int> input);
};

class PmergeMeError: public std::runtime_error
{
    public:
        PmergeMeError (std::string const& msg):
            std::runtime_error(msg)
        {}
};

#endif
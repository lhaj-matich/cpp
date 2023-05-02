#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
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
		clock_t				_dec_sort_time;
		clock_t				_vec_sort_time;
		// Parse time variables
		clock_t				_dec_parse_time;
		clock_t				_vec_parse_time;

		bool	checkNumber(char *);
		bool	checkInput(char **, int);
		void	insertNumbers(char **, int);
		void	printUnsorted(char **, int);
		void	printSortedDeque();
		void	printSortedVector();
};

class PmergeMeError: public std::runtime_error
{
    public:
        PmergeMeError (std::string const& msg):
            std::runtime_error(msg)
        {}
};

#endif
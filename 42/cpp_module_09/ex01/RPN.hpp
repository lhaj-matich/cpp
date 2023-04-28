#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

#define OPERATOR 0
#define OPERAND 1
#define SPACE 2
#define	INVALID 3

class RPN
{
	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		
		// Destructor
		~RPN();
		
		// Operators
		RPN & operator=(const RPN &assign);
		void	calculateExpression(std::string expr);
		
	private:
		std::stack<int> _dataStack;

		int		getOperand();
		int		getResult();
		int		identifyToken(char c);
		int		calculateNumbers(int a, int b, char operand);

};

class RPNError: public std::runtime_error
{
    public:
        RPNError(std::string const& msg):
            std::runtime_error(msg)
        {}
};

#endif
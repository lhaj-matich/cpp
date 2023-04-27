#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}


// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}


// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

void	RPN::calculateExpression(std::string expr)
{
	int		a;
	int		b;
	size_t	i;

	i = 0;
	while (i < expr.length())
	{
		while (i < expr.length() && this->identifyToken(expr[i]) == SPACE)
			i++;
		if (this->identifyToken(expr[i]) == OPERAND)
			this->_dataStack.push(expr[i] - '0');
		else if (this->identifyToken(expr[i]) == OPERATOR)
		{
			// Pop element a from the stack.
			b = this->getOperand();
			// Pop element b from the stack.
			std::cout << "SIZE: " << this->_dataStack.size() << std::endl;
			if (this->_dataStack.empty())
			{
				std::cout << "Error Calculating the expression" << std::endl;
				exit(1);
			}
			a = this->getOperand();
			// Appliy the operator operation and pushing the result to the stack.
			std::cout << b << " " << expr[i] << " " << a << " = " << this->calculateNumbers(a, b , expr[i]) << std::endl;
			this->_dataStack.push(this->calculateNumbers(a, b , expr[i]));
		}
		i++;
	}
	std::cout << this->_dataStack.top() << std::endl;
	//! Should clear the stack here.
}

int	RPN::getOperand()
{
	int el;
	
	el = this->_dataStack.top();
	this->_dataStack.pop();
	return (el);
}

int	RPN::calculateNumbers(int a, int b, char operand)
{

	if (operand == '+')
		return (a + b);
	else if (operand == '-')
		return (a - b);
	else if (operand == '*')
		return (a * b);
	else if (operand == '/')
		return (a / b);
	else
		std::cout << "Unkown operand, please correct the expression." << std::endl;
}

int	RPN::identifyToken(char c)
{
	std::string operators = "+-/*";
	std::string operand = "0123456789";

	if (c == ' ')
		return (SPACE);
	else if (operators.find(c) != std::string::npos)
		return (OPERATOR);
	else if (operand.find(c) != std::string::npos)
		return (OPERAND);
	else
		return (INVALID);
}
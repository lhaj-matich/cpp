#include "RPN.hpp"

// Constructors
RPN::RPN(){}

RPN::RPN(const RPN &copy) {(void) copy;}


// Destructor
RPN::~RPN(){}


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
	int		token;
	size_t	i;

	i = 0;
	while (i < expr.length())
	{
		token = this->identifyToken(expr[i]);
		if (token == OPERAND && token != SPACE)
			this->_dataStack.push(expr[i] - '0');
		else if (token == OPERATOR && token != SPACE)
		{
			if (this->_dataStack.size() < 2)
				throw RPNError("Error: Invalid Expression");
			b = this->getOperand();
			a = this->getOperand();
			this->_dataStack.push(this->calculateNumbers(a, b , expr[i]));
		}
		else if (token == INVALID)
			throw RPNError("Error: Invalid Expression");
		i += 1;
	}
	std::cout << this->getResult() << std::endl;
}

int	RPN::getOperand()
{
	int element;
	// Get the top element from the stack
	element = this->_dataStack.top();
	// Remove that element from the stack
	this->_dataStack.pop();

	return (element);
}

int RPN::getResult()
{
	int result;
	// throw invalid expression error if size large than 1
	if (this->_dataStack.size() > 1)
		throw RPNError("Error: Invalid Expression");
	// Get the value of the top element
	result = this->_dataStack.top();
	// Clear the stack for future input
	this->_dataStack.pop();
	return (result);
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
	return (0);
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
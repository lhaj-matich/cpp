# include "Intern.hpp"
# include "ShrubberCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

Form * Intern::makeForm(std::string formName, std::string target)
{
	int id;
	Form *form;

	form = NULL;
	id = findForm(formName);
	switch (id)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberCreationForm(target);
			break;
		default:
			std::cout << "Invalid form name." << std::endl;
	}
	return form;
}

int findForm(std::string form)
{
    std::string forms[] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberCreationForm"};
    for (int i = 0; i < 3; i++)
    {
        if (!strcmp(forms[i].c_str(), form.c_str()))
            return (i);
    }
    return (3);
}
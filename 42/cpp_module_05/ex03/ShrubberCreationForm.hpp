#ifndef SHRUBBERCREATIONFORM_HPP
# define SHRUBBERCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberCreationForm: public Form
{
	public:
		// Constructors
		ShrubberCreationForm();
		ShrubberCreationForm(std::string target);
		ShrubberCreationForm(const ShrubberCreationForm &copy);
		
		// Destructor
		~ShrubberCreationForm();
		
		// Copy assignement operator overload
		ShrubberCreationForm & operator=(const ShrubberCreationForm &assign);

		void	procedure( void ) const;
		
	private:
		std::string _target;
};

#endif